// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define Graph vector<vector<int>>
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1000000007;

int main(){
    int N;
    cin >> N;
    map<string, ll> M;
    rep(i, N){
        string S;
        cin >> S;
        sort(all(S));
        M[S]++;
    }

    ll sum = 0;
    for(auto i : M){
        sum += i.second * (i.second - 1) / 2;
    }

    cout << sum << endl;
}