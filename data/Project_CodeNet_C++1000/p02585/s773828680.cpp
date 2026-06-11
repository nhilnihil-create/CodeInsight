#include <iostream>//cout<<right で右揃え
#include <iomanip>//cout<<setw(数字) で空白による桁揃え
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <cstdlib>//abs()で整数絶対値
#include <cmath>//abs()かfabs()で少数絶対値
#include <functional>//sort第三引数greater<型名>()で降順
#include <map>

using namespace std;
using ll = long long int;

int main(){
    int N,K;cin>>N>>K;
    vector<int> P(N),C(N);
    for(int i=0;i<N;i++) cin >> P[i],--P[i];
    for(int i=0;i<N;i++) cin >> C[i];
    ll ans = -1000000000000000000;
    for(int i=0;i<N;i++){
        int v = i;
        int cycle_cnt = 0;
        ll cycle_score = 0;
        while(true){
            cycle_cnt++;
            cycle_score += C[v];
            v = P[v];
            if(v==i) break;
        }
        int cnt = 0;
        ll score = 0;
        while(true){
            cnt++;
            score += C[v];
            v = P[v];
            if(cnt > K) break;
            int num = (K - cnt) / cycle_cnt;
            ans = max(ans,score + max(0ll,cycle_score) * num);
            if(v==i) break;
        }
    }
    cout << ans << endl;
    return 0;
}