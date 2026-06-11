#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,n; 
int main(){
	cin>>a>>b>>n;
	n=min(n,b-1);
	cout<<a*n/b<<endl;
	return 0;
}