#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1010000000000000017LL;
const ll MOD = 1000000007LL;

#define REP(i, n) for(ll i = 0 ; i < n; i++)

#ifdef DEBUG
#define DBG(fmt, ...) fprintf(stderr, fmt "\n", ##__VA_ARGS__)
#else
#define DBG(fmt, ...)
#endif

int main(){
    std::cout<<std::fixed<<std::setprecision(10);

    ll N;
    string S;

    cin >> N >> S;

    ll ans = 0;
    for(char i = '0'; i <= '9'; i++){
    for(char k = '0'; k <= '9'; k++){
    for(char j = '0'; j <= '9'; j++){
        queue<char> q;
        q.push(i);
        q.push(j);
        q.push(k);

        for(int l = 0 ; l < S.size(); l++){
            if( q.front() == S[l] ){
                q.pop();
            }

            if( q.size() == 0 ){
                ans++;
                break;
            }
        }

    }
    }
    }

    cout << ans << endl;
}
