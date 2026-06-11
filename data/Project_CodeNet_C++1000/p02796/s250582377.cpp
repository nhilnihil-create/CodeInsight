#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()
ll d1[4] = {1, -1, 0, 0};
ll d2[4] = {0, 0, 1, -1};

int main(){
    ll N;
    cin >> N;
    vector<ll> X(N), L(N);
    vector<PL> pr(N);
    rep(i, 0, N){
        cin >> X[i] >> L[i];
        pr[i].first = X[i] + L[i];
        pr[i].second = X[i] - L[i];
    }
    sort(ALL(pr));

    cerr << "piyo" << endl;
    ll ans = 0, i = 0, now = 0;
    while(i < N){
        i = now + 1;
        while(i < N){
            if(pr[i].second < pr[now].first){
                ans++;
                i++;
            }else{
                now = i;
                break;
            }
        }
    }

    cout << N - ans << endl;
    return 0;
}