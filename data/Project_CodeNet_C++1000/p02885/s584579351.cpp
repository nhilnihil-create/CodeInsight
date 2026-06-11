#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=998244353;

int main(void){
    int a,b;
    cin>>a>>b;
    cout<<max(0,a-2*b)<<endl;
    return 0;
}