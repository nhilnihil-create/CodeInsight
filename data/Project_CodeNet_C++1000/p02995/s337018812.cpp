#include<bits/stdc++.h>
using namespace std;
#define pb          push_back
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define endl        "\n"
#define fast        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define int         long long int
#define mod         1000000007
#define test        int t;cin>>t;while(t--)
#define REP(i,a,b)  for(int i=a,i<=b;i++)
#define MAXN        200001

int32_t main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;

    int cnt1=b/c;
    cnt1-=(a-1)/c;

    int cnt2=b/d;
    cnt2-=(a-1)/d;

    // cout<<cnt1<<" "<<cnt2<<endl;
    int lcm=(c*d)/__gcd(c,d);
    int cnt3=(b)/lcm;
    cnt3-=(a-1)/lcm;

    // cout<<lcm<<"   "<<cnt3<<endl;
    cout<<(b-a+1)-(cnt1+cnt2-cnt3)<<endl;

    return 0;
}