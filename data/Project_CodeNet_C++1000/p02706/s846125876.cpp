#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll d,n,x;
	cin>>d>>n;
	while(n--) cin>>x,d-=x;
	cout<<max(d,(ll)-1)<<endl;


}
