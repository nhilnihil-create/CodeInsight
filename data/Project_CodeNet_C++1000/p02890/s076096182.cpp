#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
	int n; cin >> n; int a[n], b[n], c[n];
	for(int i=0; i<n; i++) cin >> a[i];
	fill(b, b+n, 0); fill(c, c+n, 0);
	for(int i=0; i<n; i++) b[a[i]-1]++; // xの個数
	for(int i=0; i<n; i++) {
		for(int j=0; j<b[i]; j++) c[j]++;
	}
	for(int i=1; i<n; i++) {
		c[i] += c[i-1];
	}
    //for(int x:c) cout << x << " "; cout << endl;
	for(int i=1; i<=n; i++) {
		int le=-1, ri=n;
		while(ri - le > 1) {
	      int md = (le + ri) / 2;
		  if (c[md] >= (ll)(md+1)*i) le = md; else ri = md;
          //cout << "(" << le <<" " << ri << ")" << endl;
		}
		cout << le+1 << endl;
	}
}