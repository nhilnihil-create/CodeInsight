#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define agewari(a, b) ((ll)a + ((ll)b - 1)) / b
const int MOD = 1000000007;
const long long INF = 1LL << 60;
using Graph = vector<vector<ll>>;

int main()
{
    ll h,w;
    cin>>h>>w;
    if(h==1||w==1){
        cout<<1<<endl;
    }else{
        cout<<agewari(h*w,2)<<endl;
    }
}