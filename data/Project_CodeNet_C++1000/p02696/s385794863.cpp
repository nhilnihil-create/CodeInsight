#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 1000000000
#define pi 3.14159265358979323846264338327950L
#define FOR(i,a,b) for(int i=a;i<=b;i++)

ll A,B;

ll f(ll x)
{
    ll ans=floor((A*x)/B)-(A*floor(x/B));
    return ans;
}

int main()
{
    //freopen("contest.txt","r",stdin);
    //freopen("contest.txt","w",stdout);
    IOS
    ll N;
    cin>>A>>B>>N;
    ll sum_1=0,sum_2=0;

    cout<<f(min(B-1,N))<<endl;

    return 0;
}
