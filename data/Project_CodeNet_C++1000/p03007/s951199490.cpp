#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

int main(){
    int N;
    cin >> N;
    vector<int> X;
    vector<int> Y;
    REP(i,N){
        int a;
        cin >> a;
        if(a >= 0)
            X.push_back(a);
        else
            Y.push_back(a);
    }

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    // a < 0
    if(X.size() == 0){
        vector<string> proc;
        ll ans = 0;
        ans += Y[N-1];
        REP(i,N-1){
            proc.push_back(to_string(ans) + " " + to_string(Y[i]));
            ans -= Y[i];
        }
        cout << ans << endl;
        for(auto&& s : proc){
            cout << s << endl;
        }
    }
    // a > 0
    else if(Y.size() == 0){
        vector<string> proc;
        ll ans = 0;
        ans += X[0];
        for(int i = 1; i < N-1; i++){
            proc.push_back(to_string(ans) + " " + to_string(X[i]));
            ans -= X[i];
        }
        proc.push_back(to_string(X[N-1]) + " " + to_string(ans));
        ans = X[N-1] - ans;

        cout << ans << endl;
        for(auto&& s : proc){
            cout << s << endl;
        }

    }
    else{
        vector<string> proc;
        ll tmp1 = 0;
        ll tmp2 = 0;
        int XX = X.size();
        int YY = Y.size();

        tmp1 = X[XX-1];
        for(int i = 1; i < YY; i++){
            proc.push_back(to_string(tmp1) + " " + to_string(Y[i]));
            tmp1 -= Y[i];
        }

        tmp2 = Y[0];
        for(int i = 0; i < XX-1; i++){
            proc.push_back(to_string(tmp2) + " " + to_string(X[i]));
            tmp2 -= X[i];
        }

        proc.push_back(to_string(tmp1) + " " + to_string(tmp2));
        ll ans = tmp1 - tmp2;

        cout << ans << endl;
        for(auto&& s : proc){
            cout << s << endl;
        }

    }
    return 0;
}
