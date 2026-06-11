#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

int main(){
    int N;
    string s1, s2;
    cin >> N;
    vector<pair<int, int>> A(N);
    rep(i, N){
        int a;
        cin >> a;
        A[i] = make_pair(-1 * a, i);
    }
    sort(all(A));
    // cout << A[0].first << endl;
    rep(i, N){
        if(i == A[0].second) cout << A[1].first * -1 << endl;
        else cout << A[0].first * -1 << endl;
    }
}