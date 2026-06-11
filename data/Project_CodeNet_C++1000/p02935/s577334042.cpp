#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

int main(){
    int N; cin >> N;
    priority_queue<double, vector<double>, greater<double>> pq;
    rep(i, N){
        double v; cin >> v;
        pq.push(v);
    }
    rep(i, N - 1){
        double a, b;
        a = pq.top(); pq.pop();
        b = pq.top(); pq.pop();
        pq.push((a + b) / 2.0);
    }
    cout << pq.top() << endl;
} 