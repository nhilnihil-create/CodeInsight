#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define line cout<<"----------------------------------"<<endl
#define fast ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define filein freopen("input.txt","r",stdin)
#define fileout freopen("output.txt","w",stdout)
using namespace std;
const ll mx=400009;
int a[mx],b[mx],c[mx]; 
int  main()
{
    int n ;
    cin>>n; 
    int sum=0; 
    for(int i=1;i<=n;i++) cin>>a[i]; 
    for(int i=1;i<=n;i++) cin>>b[i]; 
    for(int i=1;i<=n-1;i++) cin>>c[i]; 
    for(int i=1;i<=n;i++)
    {
        sum+=b[i]; 
        if(a[i]==a[i-1]+1) sum+=c[a[i]-1]; 
    }
    cout<<sum<<endl; 
}
