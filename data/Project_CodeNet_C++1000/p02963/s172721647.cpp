#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()



int main() {
    ll s;
    cin>>s;
    const int v=1000000000;

    int x=(v-s%v)%v;
    int y=(s+x)/v;
    cout<<"0 0 1000000000 1 "<<x<<" "<<y<<endl;
}

