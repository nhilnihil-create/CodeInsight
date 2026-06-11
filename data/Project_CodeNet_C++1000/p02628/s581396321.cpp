#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi   = vector<int>;
using vll  = vector<ll>;
using vc   = vector<char>;
using vvll  = vector<vll>;
using vvi  = vector<vi>;
using vvc  = vector<vc>;
using vb   = vector<bool>;
using vvb  = vector<vb>;
using pii  = pair<int,int>;
using vpii = vector<pii>;
using posteriority_queue = priority_queue<int, vi, greater<int>>;


int main() {
    int N, K; cin >> N >> K;
    int ans = 0;
    posteriority_queue que;
    vi p(N);
    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        que.push(tmp);
    }

    for(int i = 0; i < K; i++){
        ans += que.top();
        que.pop();
    }

    cout << ans << endl;

}