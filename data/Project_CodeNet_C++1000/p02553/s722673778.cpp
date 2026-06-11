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

int main() {
    FASTIO
    ll a,b,c,d,d1,d2,d3,d4;
    cin>>a>>b>>c>>d;
    d1=a*c;d2=a*d;d3=b*c;d4=b*d;
    cout<<max({d1,d2,d3,d4})<<endl;
    return 0;
}
