#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define int ll
#define pb push_back
#define setbits(x)          __builtin_popcountll(x)
#define endl "\n"
typedef long long ll;
int32_t main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n,k,s;
cin>>n>>k>>s;
for(int i=0;i<k;i++)
    cout<<s<<" ";
    int x=pow(10,9);
for(int i=k;i<n;i++)
{
    if(s==x)
        cout<<x-1<<" ";
    else
        cout<<x<<" ";
}
cout<<endl;
    return 0;
}
