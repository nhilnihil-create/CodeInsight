#include <bits/stdc++.h>
using namespace std;

int n, r;

int main(){
//	cin.tie(0);
//	ios::sync_with_stdio(false);
	while(1){
		cin >> n >> r;
		if(n == 0 && r == 0) return 0;
		int a[n] = {};
		for(int i=0; i<n; ++i)
			a[i] = n-i;
//		for(int i=0; i<n; ++i)
//			cout << a[i] << (i==n-1?"\n":" ");
		for(int i=0; i<r; ++i){
			int p, c;
			cin >> p >> c;
			int b[c] = {};
			for(int i=0; i<c; ++i)
				b[i] = a[p+i-1];
			for(int i=p-2; i>=0; --i)
				a[c+i] = a[i];
//			for(int i=0; i<n; ++i)
//				cout << a[i] << (i==n-1?"\n":" ");
			for(int i=0; i<c; ++i)
				a[i] = b[i];
//			for(int i=0; i<n; ++i)
//				cout << a[i] << (i==n-1?"\n":" ");
		}
		cout << a[0] << "\n";
	}
}
