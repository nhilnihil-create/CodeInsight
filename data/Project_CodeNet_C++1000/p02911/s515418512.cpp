#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

int main(){
    int N, K, Q; cin >> N >> K >> Q;
    vector<int> A(N, 0);
    rep(i, Q){
        int n; cin >> n;
        A[n - 1]++;
    }
    vector<int> points(N, K);
    rep(i, N){
        points[i] = points[i] - Q + A[i];
        if(points[i] <= 0) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}