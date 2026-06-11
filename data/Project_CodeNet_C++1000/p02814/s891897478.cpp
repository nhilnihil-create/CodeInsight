// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define Graph vector<vector<int>>
typedef long long ll;
typedef pair<int, int> P;
const ll INF = 1000000007;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    rep(i, N){
        cin >> A[i];
        A[i] /= 2;
    }

    ll ans = A[0];
    for(int i = 1; i < N; i++){
        ll next = lcm(A[i], ans);
        int a = next / ans, b = next / A[i];
        while(1){
            if(a % 2 != b % 2){
                ans = INF;
                break;
            }
            else if( a % 2 == 0 && b % 2 == 0){
                a /= 2;
                b /= 2;
            }
            else {
                ans = next;
                break;
            }
        }
        if(ans == INF) break; 
    }

    int sum = 0;
    for(int i = 1; i * ans <= M; i +=2 ) sum++;
    cout << sum << endl;
}