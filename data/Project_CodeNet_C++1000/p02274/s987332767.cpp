#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

const int INF = 1001001001;
ll co = 0;

void merge(vector<int> &a, int left, int mid, int right){
	int n1 = mid - left;
	int n2 = right - mid;
	vector<int> l(n1+1), r(n2+1);
	rep(i, n1) l.at(i) = a.at(left+i);
	rep(i, n2) r.at(i) = a.at(mid+i);
	l.at(n1) = r.at(n2) = INF;
	int i = 0, j = 0;
	for(int k = left; k < right; k++){
		if(l.at(i) <= r.at(j)){
			a.at(k) = l.at(i);
			i++;
		}else{
			co += n1 - i;
			a.at(k) = r.at(j);
			j++;
		}
	}
}

void mergeSort(vector<int> &a, int left, int right){
	if(left + 1 < right){
		int mid = (left+right)/2;
		mergeSort(a, left, mid);
		mergeSort(a, mid, right);
		merge(a, left, mid, right);
	}
}

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	rep(snip_i, n) cin >> a.at(snip_i);
	mergeSort(a, 0, n);
	cout << co << endl;
	return 0;
}
