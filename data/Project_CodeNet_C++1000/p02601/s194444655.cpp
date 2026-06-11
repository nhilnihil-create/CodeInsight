#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

int main(){
    int A, B, C; cin >> A >> B >> C;
    int K; cin >> K;
    rep(i, K){
        if(A >= B) B*= 2;
        else C *= 2;
    }
    if(A < B && B < C) cout << "Yes" << endl;
    else cout << "No" << endl;
} 