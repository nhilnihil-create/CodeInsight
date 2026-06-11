//Author: A_S_M_M@sud_P@rvez
#include<bits/stdc++.h>
using namespace std;
#define    MP ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define    for0(i,n) for(int i=0;i<n;i++)
#define    forn(i,n) for(int i=1;i<=n;i++)
#define    fors(i,s) for(int i=0;i<s.size();i++)
#define    Sort(s) sort(s.begin(),s.end())
#define    gcd(a, b) __gcd(a , b)
#define    lcm(a,b) (a*(b/__gcd(a,b)))
#define    nl     "\n"
#define    End    return 0 
#define    gt     greater<int>()
#define    ll     long long int
#define    mp     make_pair
#define    pb     push_back
#define    vi     vector<int>
#define    vl     vector<ll>
#define    mod    1000000007
#define    sp(n)  fixed<<setprecision(n)
#define    pi     acos(-1)

int main()
{
MP;
	
    int n,t,m,c=0;
    cin>>n>>t;
    bool p[n+1];
    forn(i,n)p[i]=0;
    while(t--)
    {
        cin>>m;
        int a;
        while(m--)
        {
            cin>>a;
            p[a]=1;
        }
    }
    forn(i,n){
        if(p[i]==0)c++;
    }
    cout<<c;
    
End;
}
