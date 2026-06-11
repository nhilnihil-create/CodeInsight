#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int main(){
    ll N, K, R, S, P;
    cin >> N >> K >> R >> S >> P;
    string T;
    cin >> T;

    vector<ll> score(N, 0);
    for (ll i = 0; i < N; i++) {
        if(i < K){
            if(T[i] == 'r'){
                score[i] = P;
            }
            else if(T[i] == 's'){
                score[i] = R;
            }
            else{
                score[i] = S;
            }
        }
        else{
            if(T[i] == T[i-K]){
                if(score[i-K] > 0){
                    score[i] = 0;
                }
                else{
                    if(T[i] == 'r'){
                        score[i] = P;
                    }
                    else if(T[i] == 's'){
                        score[i] = R;
                    }
                    else{
                        score[i] = S;
                    }
                }
            }
            else if(T[i] == 'r'){
                score[i] = P;
            }
            else if(T[i] == 's'){
                score[i] = R;
            }
            else{
                score[i] = S;
            }
        }
    }

    ll ans = 0;
    for (ll i = 0; i < N; i++) {
        ans += score[i];
    }

    printf("%lld\n", ans);
}