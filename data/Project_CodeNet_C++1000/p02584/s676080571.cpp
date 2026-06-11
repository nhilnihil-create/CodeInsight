#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
int main(){
	//freopen("input.in","r",stdin);
	//freopen("output.in","w",stdout);
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll i,j,k,n,x,d;
    cin>>x>>k>>d;
    x=abs(x);
    ll temp=x/d;
    temp=min(k,temp);
    k-=temp;
    if(k&1^1)cout<<x-d*temp;
    else cout<<min(abs((x-d*temp)+d),abs((x-d*temp)-d));

 
	
	
	
 
 
 
 
 
 
 
	return 0;
}