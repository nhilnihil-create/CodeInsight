#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
ll INFL = 1000000000000000010;//10^18 = 2^60
int INF = 2000000000;//10^9
ll MOD  = 998244353;


int main() {
    while(true){
        int N,K;
        cin >> N >> K;
        if(N == 0 && K == 0)break;
        vector<int> a(N);
        vector<int> wa(N+1);
        wa.at(0) = 0;
        for(int i = 0; i < N; i++){
            cin >> a.at(i);
            wa.at(i+1) = a.at(i) + wa.at(i);
        }
        int ANS = -INF;
        for(int i = 0; i < N - K +1; i++){
            int ans = wa.at(i+K) - wa.at(i);
            ANS = max(ANS, ans);
        }
        cout << ANS << endl;
    }
    
    
    
    
}
