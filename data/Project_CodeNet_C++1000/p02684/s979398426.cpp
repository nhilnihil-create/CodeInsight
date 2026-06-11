#include <algorithm>
#include <cmath>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <numeric>
#include <vector>
#include <map>

using namespace std;
using ll = long long;
template<typename T> void print(T t) {cout << t << endl;}

vector<pair<ll, int>> prime_factorize(ll n) {
    vector < pair < ll, int >> res;
    int num = 0;
    while (n % 2 == 0) {
        num++;
        n /= 2;
    }
    if (num != 0) res.emplace_back(make_pair( 2, num ));

    for (ll p = 3; p * p <= n; p += 2) {
        num = 0;
        while (n % p == 0) {
            num++;
            n /= p;
        }
        if (num != 0) res.emplace_back(make_pair(p, num));
    }
    if (n != 1)res.emplace_back(make_pair(n, 1));
    return res;
}


struct Room {
    int id, mark, step;
    vector<int> vicinities;
};

int main() {
    int N;
    ll K;
    cin >> N >> K;
    vector<int> As(N + 1);
    vector<int> steps(N + 1, -1);
    for (int i = 1; i <= N; i++) cin >> As[i];
    
    int step = 0, now=1, loop=1;
    steps[1] = step;
    while(true){
        now = As[now];
        step++;

        if (steps[now] == -1) {
            steps[now] = step;
            
        }
        else {
            loop = step - steps[now];
            step -= loop;
            break;
        }
    }

    if(K-step>0) K = step + (K - step) % loop;
    now = 1;
    for (ll t = 0; t < K; t++) {
        now = As[now];
    }
    print(now);
}

