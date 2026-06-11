#include <bits/stdc++.h>

using namespace std;
#define repr(i,a,b) for (int i=a; i<b; i++)
#define rep(i,n) for (int i=0; i<  n; i++)
 
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const long long INF = 1LL << 60;

bool dp[100100];

int main () {
    int N;
    cin >> N;

    vector<int>w(N);
    rep(i,N){
        cin >> w[i];
    }

    int ans =100000;
    repr(i,0,N){
        int s1=0;
        int s2=0;

        rep(j,i+1){
            s1+= w[j];
        }
        repr(j,i+1,N){
            s2+= w[j];
        }
        ans =min(ans,abs(s1-s2));
    }

    cout << ans << endl;

}

