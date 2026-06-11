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

    ll y2=(s+v-1)/v;
    ll y1=v*y2-s;
    cout<<"1000000000 "<<y1<<" 1 "<<y2<<" 0 0"<<endl;
}

