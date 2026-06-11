#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    ll N, K;
    cin >> N >> K;
    N=N-(N/K)*K;
    ll ans=1e19;
    ll pre[2]={-1, -1};
    int pre_num=0;
    while(true){
        N=abs(K-N);
        if(N <= ans) ans=N;
        if(pre[pre_num]==N) break;
        pre[pre_num]=N;
        pre_num=(pre_num+1)%2;
    }
    cout << ans << endl;
    return 0;
}