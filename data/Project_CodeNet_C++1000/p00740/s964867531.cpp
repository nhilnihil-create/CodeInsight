#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
main(){
    int N,P;
    cin >> N >> P;
    while(N){
        int num = P,turn = 0;
        vector<int> V(N);
        while(1){
            if(num){
                V[turn]++;
                num--;
            }else{
                num = V[turn];
                V[turn] = 0;
            }
            if(!num){
                int cnt = 0,ans;
                rep(i,0,N){
                    cnt += V[i] != 0;
                    if(V[i] != 0)ans = i;
                }
                if(cnt == 1){
                    cout << ans << endl;
                    break;
                }
            }
            turn = (turn + 1) % N;
        }
        cin >> N >> P;
    }
}
