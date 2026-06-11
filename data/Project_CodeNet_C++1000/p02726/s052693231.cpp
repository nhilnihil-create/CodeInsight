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
const ll mx=200009;
int cnt[mx]; 
int main()
{
    int n,a,b;
    cin>>n>>a>>b; 
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            int dis=min(fabs(i-j),fabs(i-a)+1+fabs(j-b));
            cnt[dis]++; 
        }
    }
    for(int i=1;i<n;i++) cout<<cnt[i]<<endl; 
}
