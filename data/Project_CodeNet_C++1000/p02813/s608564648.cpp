#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int n;

int main(void){
	cin >> n;
	vector<int> p(n), q(n);
	rep(i, n) cin >> p[i];
	rep(i, n) cin >> q[i];
	vector<int> a(n);
	rep(i, n) a[i] = i+1;
	int pi, qi;
	int c = 1;
	do{
		bool fp, fq;
		fp = fq = true;
		rep(i, n){
			if(a[i] != p[i]) fp = false;
			if(a[i] != q[i]) fq = false;
		}
		if(fp) pi = c;
		if(fq) qi = c;
		c++;
	}while(next_permutation(a.begin(), a.end()));
	cout << abs(pi-qi) << endl;
}
