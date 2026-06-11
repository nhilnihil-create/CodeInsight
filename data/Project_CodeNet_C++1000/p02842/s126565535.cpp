#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int n; cin>>n;
	int a=(n*100)/108;
	int b=(n*100+108-1)/108;
	if(n==a*108/100) cout<<a<<endl;
	else if(n==b*108/100) cout<<b<<endl;
	else cout<<":("<<endl;
}