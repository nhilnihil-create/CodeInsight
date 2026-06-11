#include<bits/stdc++.h>
#define REP(i, n) for(int i=0; i<n; i++)
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
using namespace std;
using ll = long long;
using Graph = vector<vector<ll>>;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    int X, N;
    cin >> X >> N;
    int p[N];
    for (int i = 0; i < N; i++)
    {
        cin >> p[i];
    }
    int dmin = 1000;
    int ans  = -1;
    for (int i = -1; i <= 101; i++)
    {
        bool flag = true;
        for (int j = 0; j < N; j++)
        {
            if(i==p[j]) flag = false;
        }
        if(flag){
            int d = max(X,i)-min(X,i);
            if(d<dmin){
                dmin = d;
                ans = i;
            }
        }   
    }
    
    cout << ans << endl;
}