#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=998244353;

int main(void){
    int n,d;
    cin>>n>>d;
    int ans=(n+2*d)/(2*d+1);
    cout<<ans<<endl;
    return 0;
}