#include <bits/stdc++.h> 
using namespace std; 
#define rep(i,a,b)		for(int i=a;i<=b;i++)

long int n,l,s,e,c,ans;
int main() 
{ 

	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>l;
    s = l;
    e = l+n-1;

    if(e<=0)
    	c = e;
    else if(s>=0)
    	c = s;
    else
    	c = 0;
    ans = (((s+e)*(e-s+1))/2)-c;
    cout<<ans;

} 
