#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 3e5 + 5;

int n, a[N], xum, ok = 1;

int main() {
	cin>>n;
	for(int i = 1; i <= n; i++) {
		cin>>a[i];
		xum = xum^a[i];
	}
	if(xum) cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
}