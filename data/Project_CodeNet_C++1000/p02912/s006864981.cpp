 #include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define fr(i,n) for(i=0;i<n;i++)
#define F first
#define S second
#define fast std::ios_base::sync_with_stdio(false)
#define mod 1000000007
#define pi 3.14159265
int main() {
    fast;
    lli n,m;
    cin>>n>>m;
    lli a[n],i;
    priority_queue<lli>p;
    fr(i,n)
    {
        cin>>a[i];
        p.push(a[i]);
    }
    fr(i,m)
    {
        lli temp=p.top();
        p.pop();
        temp/=2;
        p.push(temp);
    }
    lli sum=0;
    while(!p.empty())
    {
        sum+=p.top();
        p.pop();
    }
    cout<<sum;
    
    return 0;
}