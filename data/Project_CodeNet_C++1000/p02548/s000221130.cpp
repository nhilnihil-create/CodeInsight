#include<bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define REP(i,a,b) for(int i=a;i<b;i++)
#define maxx 1000001
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int main(){
    FASTIO
    ll n,ans=0;
    cin>>n;
    n--;
    for(int i=1;i<=n;i++)
        ans+=n/i;
    cout<<ans<<endl;
    return 0;
}
