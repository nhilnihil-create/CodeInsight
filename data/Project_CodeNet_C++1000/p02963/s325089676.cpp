#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const int MOD = 1000000007;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

vector<ll> m(1001,0);

int main(){
    long long s;
    cin>>s;

    const int v=1000000000;

    int x=(v-s%v)%v;
    int y=(s+x)/v;

    // 0 0 1000000000 1 435958503 311114771

    cout<<"0 0 1000000000 1 "<<x<<" "<<y<<endl;
}