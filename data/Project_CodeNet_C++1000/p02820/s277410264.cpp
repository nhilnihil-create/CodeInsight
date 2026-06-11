#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N, K, R, S, P;
    cin >> N >> K >> R >> S >> P;
    string T;
    cin >> T;
    vector<string> U(N);
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        if (i < K)
        {
            if (T[i] == 'r') {
                U[i] = "p";
                ans += P;
            } else if (T[i] == 's') {
                U[i] = "r";
                ans += R;
            } else
            {
                U[i] = "s";
                ans += S;
            }
            continue;
        }
        if (T[i] == 'r')
        {
            if (U[i - K] == "p")
            {
                U[i] = "rs";
            } else
            {
                U[i] = "p";
                ans += P;                
            }
        } else if (T[i] == 's') {
            if (U[i - K] == "r"){
                U[i] = "sp";
            } else
            {
                U[i] = "r";
                ans += R;
            }
        } else
        {
            if (U[i - K] == "s") {
                U[i] = "pr";
            } else
            {
                U[i] = "s";
                ans += S;                
            }   
        }      
    }
    cout << ans << endl;

  return 0;
}
