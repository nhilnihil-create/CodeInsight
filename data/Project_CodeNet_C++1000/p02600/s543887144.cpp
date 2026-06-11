#define    ll           long long
#define    dn           double
#define    mp           make_pair
#define    pb           push_back
#define    se           second
#define    fi           first
#define    mod          1000000007
#define    sob(v)       v.begin(),v.end()
#define    sobr(v)      v.rbegin(),v.rend()
#define    fr(i,a,b)    for(int i=a;i<=b;++i)
#define    frr(i,a,b)   for(int i=a;i>=b;--i)
#define    pi           acos(-1.00)
#define    check        cout<<"*"<<endl
#define    ffix(x)      cout<<fixed<<setprecision(x)
#define    fast         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

#include<bits/stdc++.h>
#include<string.h>
using namespace std;


typedef vector<int> vi;
typedef map<int,int> mii;
typedef pair<int,int> pii;
typedef pair<int,vi> pp;

int dr[8]= {0,0,-1,1,-1,-1,+1,+1};
int dc[8]= {-1,1,0,0,-1,+1,-1,+1};

const int N=2000000;

int main()
{
    int n,ans;
    cin>>n;
    if(n>=400 && n<=599)
        ans=8;
    else if(n>=600 && n<=799)
        ans=7;
    else if(n>=800 && n<=999)
        ans=6;
    else if(n>=1000 && n<=1199)
        ans=5;
    else if(n>=1200 && n<=1399)
        ans=4;
    else if(n>=1400 && n<=1599)
        ans=3;
    else if(n>=1600 && n<=1799)
        ans=2;
    else if(n>=1800 && n<=1999)
        ans=1;
    cout<<ans<<endl;
}
