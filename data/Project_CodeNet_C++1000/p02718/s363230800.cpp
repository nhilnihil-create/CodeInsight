#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a[105], sel=0;
double thres, sum=0, m;
int main() {
	cin >> n >> m;
  	for (int i=0; i<n; i++) {
		cin >> a[i];
      	sum+=a[i];
    }
  	thres=sum/(4*m);
  	for (int i=0; i<n; i++) {
		if (a[i]>=thres) sel++;
    }
  	cout << (sel>=m ? "Yes\n" : "No\n");
}