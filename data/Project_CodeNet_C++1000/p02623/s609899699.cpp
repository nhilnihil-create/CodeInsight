#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define pb push_back
#define READ(FILE) freopen(FILE,"r",stdin)
#define WRITE(FILE) freopen(FILE,"w",stdout)
#define loop(i,s,e) for(int i=s;i<e;i++)
#define mego fast();
using namespace std;
void fast()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll lcm(ll x, ll y)
{
    return (x*y)/__gcd(x,y);
}
int sum(string s)
{
    int x=0,sz=s.size();
    loop(i,0,sz)x+=(s[i]-'0');
    return x;
}

int main()
{
    mego
vector<ll> q1,q2;
int n,m,k,x;
cin>>n>>m>>k;
loop(i,0,n)
{
    cin>>x;
    q1.pb(x);
}
loop(i,0,m){cin>>x;q2.pb(x);}
int ans=0;
//cout<<q1.front()<<" "<<q2.front()<<endl;

x=0;
loop(i,1,n)
q1[i]+=q1[i-1];
loop(i,0,m+1)
{
    if(x>k)break;
    int st=i+(upper_bound(q1.begin(),q1.end(),k-x)-q1.begin());
    ans=max(ans,st);
   if(i<m) x+=q2[i];

}

cout<<ans;
    return 0;
}
//greedy won't work on corner cases like
/*
2 2 11
11 2
10 1
greedy:11
optimal:10,1
*/
