#include <bits/stdc++.h>
#include<iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

typedef long long ll;
typedef pair<ll, ll> P;

const ll mod =  1000000007;  //出力は (ans % mod + mod) % mod  (負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INF = 1152921504606846976
const double PI = 3.1415926535897932;

vector<int> Zalgo(const string &S) {
    int N = (int)S.size();
    vector<int> res(N);
    res[0] = N;
    int i = 1, j = 0;
    while (i < N) {
        while (i+j < N && S[j] == S[i+j]) ++j;
        res[i] = j;
        if (j == 0) {++i; continue;}
        int k = 1;
        while (i+k < N && k+res[k] < j) res[i+k] = res[k], ++k;
        i += k, j -= k;
    }
    return res;
}

int main()
{
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    rep(i,n){
        string t = s.substr(i);
        auto vec = Zalgo(t);
        rep(j,vec.size()){
            if(j >= vec[j]) ans = max(ans,vec[j]);
        }
    }
    cout << ans << endl;
}