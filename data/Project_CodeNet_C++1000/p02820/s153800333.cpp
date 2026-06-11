#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793
#define MOD 1000000007
typedef long long ll;
typedef long double ld;

int main() {
    ll N, K, R, S, P;
    string T;
    cin >> N >> K >> R >> S >> P >> T;
    ll ans = 0;
    for(int i = 0; i < N; i++){
        if(T[i] == 's'){
            ans += R;
        }
        else if(T[i] == 'r'){
            ans += P;
        }
        else{
            ans += S;
        }
    }

    for(int i = 0; i < N - K; i++){
        if(T[i] == T[i + K]){
            if(T[i] == 's'){
                ans -= R;
                T[i + K] = '*';
            }
            else if(T[i] == 'r'){
                ans -= P;
                T[i + K] = '*';
            }
            else{
                ans -= S;
                T[i + K] = '*';
            }            
        }
    }

    cout << ans << endl;
}
