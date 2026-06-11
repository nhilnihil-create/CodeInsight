#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    int N; cin>>N;
    vector<int> vW(N);

    int total=0;
    rep(i,N){
        int x; cin>>x;
        total += x;
        vW[i]=x;
    }

    int ans = 1e9;
    int left = 0;
    for(int i=0; i<N; i++){
        left += vW[i];
        ans = min(ans , abs(left - (total-left)));
    }
    cout << ans << endl;
}
