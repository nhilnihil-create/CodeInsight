#include<bits/stdc++.h>
using namespace std;
                       ///****   Hasebul Hassan Chowdhury ***////
#define ms(a,v)        memset(a,v,sizeof a)
#define lll            long long
#define FOR(i,a,b)     for(int i=a;i<=b;i++)
#define fast           ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define Read           freopen("input.txt", "r", stdin)
#define Write          freopen("output.txt", "w", stdout)
#define INF            1000000000


int main()
{
    int n;
    cin>>n;
    lll Mod=n%500;
    lll div=n/500;
    lll ans=0;
    ans+=(div)*1000;
    ans+=(Mod/5)*5;
    cout<<ans<<endl;
}
