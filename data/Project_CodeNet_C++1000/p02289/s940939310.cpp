#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;
using v1 = vector<int>;
using vl = vector<long long>;
using v2 = vector<vector<int>>;
using v3 = vector<vector<char>>;

int N = 0;

void maxHeap(vl& a, int x){
	int l = x*2;
	int r = x*2+1;
	int largest = 0;
	if(l <= N && a[l] > a[x]){
		largest = l;
	}else{
		largest = x;
	}
	if(r <= N && a[r] > a[largest]) largest = r;
	if(largest != x){
		ll y = a[x];
		a[x] = a[largest];
		a[largest] = y;
		maxHeap(a, largest);
	}
}

void increaseKey(vl& a, int i, ll key){
	if(a[i] >= key) return;
	a[i] = key;
	while(i >1 && a[i/2] < a[i]){
		int y = a[i];
		a[i] = a[i/2];
		a[i/2] = y;
		i /= 2;
	}
}

void insert(vl& a, ll key){
	N++;
	a[N] = -1e10;
	increaseKey(a, N, key);
}

ll extract(vl& a){
	ll root = a[1];
	a[1] = a[N];
	N--;
	maxHeap(a, 1);
	return root;
}

int main(){
	vl a(2000001);
	string s;
	ll k;
	while(1){
		cin >> s;
	if(s[0] == 'i'){
		cin >> k;
		insert(a, k);
	}
	if(s == "extract"){
		cout << extract(a) << endl;
	}
	if(s == "end"){
		return 0;
	}
}
}

