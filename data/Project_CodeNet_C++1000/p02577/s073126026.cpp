#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define forn(n1,n2) for(ll i=n1;i<n2;i++)
#define w(t) ll t;cin>>t;while(t--)
#define en "\n"
#define mod 1e6+3
#define f first
# define s second
using namespace std;
ll i,n,m,x,y,z,j,k,l,mn=LLONG_MAX,mx=0,c,a[100005],r,cnt=0,sum=0;
string str;char ch;set<ll>s;map<ll,ll>mp;
vector<vector<ll>>g;
vector<ll>v;
void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
} 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>str;ll len=str.size();
    forn(0,len)
    {sum+=str[i]-48;}
    sum%9==0?cout<<"Yes":cout<<"No";
    return 0;
}