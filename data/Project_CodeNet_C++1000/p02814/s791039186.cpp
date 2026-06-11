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

    int div2 = 0;
    bool flag = true;

    rep(i, N){
        int count = 0, tmp = A[i];
        while(tmp % 2 == 0){
            count++;
            tmp /= 2;
        }
        if(i == 0) div2 = count;
        else if(div2 != count){
            flag = false;
            break;
        }
    }

    if(flag){
        ll lcm_cal = A[0];
        bool flag2 = true;
        for(int i = 1; i < N; i++){
            lcm_cal = lcm(lcm_cal, A[i]);
            if(lcm_cal > M){
                flag2 = false;
                break;
            }
        }
        if(flag2){
            int sum = 0;
            for(ll i = 1; i * lcm_cal <= M; i += 2) sum++;
            cout << sum << endl;
            return 0;
        }
    }
    
    cout << 0 << endl;
}