#include <iostream>
#include <math.h>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <cstdlib>
#include <unordered_map>
#include <numeric>
#include <functional>
#include <limits.h>
#include <utility>
#include <stack>

using namespace std;

#define fs first
#define sc second

typedef long long ll;
typedef pair<ll, ll> P;


int main(){
    int N;
    priority_queue<P> que;
    ll a[210000], b[210000];
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    for(int i = 0; i < N; i++){
        cin >> b[i];
        que.push(P(b[i], i));
    }

    ll res = 0;
    while(!que.empty()){
        P x = que.top(); que.pop();
        int index = x.sc;
        if(a[index] == b[index]){
            continue;
        }
        ll nextB, trial;
        if(a[index] >= max(b[(index + N + 1) % N], b[(index + N - 1) % N])){
            trial = (b[index] - a[index]) / (b[(index + N + 1) % N] + b[(index + N - 1) % N]);
            nextB = b[index] - (b[(index + N + 1) % N] + b[(index + N - 1) % N]) * trial;
            if(nextB != a[index]){
                cout << -1 << endl;
                return 0;
            }
        }
        else{
            ll nextBMax = max(b[(index + N + 1) % N], b[(index + N - 1) % N]);
            trial = (b[index] - nextBMax) / (b[(index + N + 1) % N] + b[(index + N - 1) % N]) + 1;
            nextB = b[index] - (b[(index + N + 1) % N] + b[(index + N - 1) % N]) * trial;
        }

        if(nextB < a[index]){
            cout << -1 << endl;
            return 0;
        }
        else if(nextB > a[index]){
            que.push(P(nextB, index));
        }
        b[index] = nextB;
        res += trial;
    }

    cout << res << endl;


    return 0;
}