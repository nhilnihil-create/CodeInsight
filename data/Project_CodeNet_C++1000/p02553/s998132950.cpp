#include<bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define endl '\n'

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;


int main()
{
    ll a,b,c,d,ans=-1e18;
    cin>>a>>b>>c>>d;
    ans=max(ans,a*c);
    ans=max(ans,a*d);
    ans=max(ans,b*c);
    ans=max(ans,b*d);
    cout<<ans<<endl;
    return 0;
}