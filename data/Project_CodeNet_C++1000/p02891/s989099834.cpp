#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,a,b) for (int i = (a); i < (b); i++ )
typedef pair<int,int> P;
typedef long long ll;
const int INF = 100000000;
const double PI=3.14159265358979323846;

int main (){
    string S;
    ll K;
    cin >> S >> K;

    ll ans = 0;

    if (S.back()!=S.front()) {
        rep(i,1,S.size()) {
            if (S[i-1]==S[i]) {
                ans++;
                i++;
            }
        }
        ans *=K;
        cout << ans << endl;
    }

    else {
        string tmp = S;
        tmp.erase(unique(tmp.begin(), tmp.end()),tmp.end());

        if (tmp.size()==1) {
            ans = S.size()*K/2;
            cout << ans << endl;
        }

        else {
            rep(i,1,S.size()) {
                if (S[i-1]==S[i]) {
                    ans++;
                    i++;
                }
            }
            S+=S;

            int ans2=0;
            rep(i,1,S.size()) {
                if (S[i-1]==S[i]) {
                    ans2++;
                    i++;
                }
            }
            ans = ans + (K-1)*(ans2-ans);
            cout << ans << endl;
        }
    }

    
}



