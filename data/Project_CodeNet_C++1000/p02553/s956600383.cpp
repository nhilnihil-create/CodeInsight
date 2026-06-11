#include<bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define REP(i,a,b) for(int i=a;i<b;i++)
#define maxx 100005
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int main() {
    FASTIO
    ll a,b,c,d,a1,a2,a3,a4;
    cin>>a>>b>>c>>d;
    a1=a*c;a2=a*d;
    a3=b*c;a4=b*d;
    cout<<max({a1,a2,a3,a4})<<endl;
    return 0;
}
