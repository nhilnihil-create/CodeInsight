#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define scn(n) scanf("%d",&n)
const int N=1e7+2;
using namespace std;

int main() {
	
    int n;
    cin>>n;
    
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        ll cnt=n/i; // in how many nos i is a factor
        
        cnt=cnt*(cnt+1);
        cnt/=2;
        
        ans+=(cnt*i);
        
    }
    cout<<ans;
	return 0;
}