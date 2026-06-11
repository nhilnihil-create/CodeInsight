#include<bits/stdc++.h>
#include<string.h>
#define pb push_back
#define all(v) v.begin(),v.end()
#define see(x) cout<<#x<<" : "<<(x)<<endl;
#define ya cout<<"yes"<<endl;
#define no cout<<"no"<<endl;
#define ff first
#define sc second
typedef  long long ll;
using namespace std;
const ll N=1e5+7;
ll n,k,i,j,ans;
int main()
{
//    ios::sync_with_stdio(false);
//    cin.tie(NULL),cout.tie(NULL);
    cin>>n>>k;
    if((n==k) || k==1 || n==0)
    {
        cout<<0<<endl;
        return 0;
    }
    if(n<k)
    {
        k=n-k;
        if(k<0)k=-k;
        cout<<(ll)min(n,k)<<endl;
    }
    else
    {
        ll p=n%k;
        k=k-p;
        if(k<0)k=-k;
        cout<<(ll)min(n,k)<<endl;
    }
    return 0;
}
