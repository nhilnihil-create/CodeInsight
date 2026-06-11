#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=0;(i)<(n);i++)
#define INF 1001001001
#define LLINF 1001001001001001001
#define MOD 1000000007
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define ALL(v) v.begin(), v.end()
typedef long long ll;

int main(){
    int n,m,x;
    cin >> n >> m >> x;
    int c[n],a[n][m],score[m];
    for(int i=0;i<n;i++){
        cin >> c[i];
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }

    int cost0 = INF;

    for(int bit=0; bit < (1<<n);bit++){
        bool ok = true;
        ll cost=0;
        int sum=0;
        int score[m];rep(l,m)score[l]=0;

        for(int i=0;i<n;i++){
            if(bit & (1<<i)){
                cost = cost +c[i];
                for(int j=0;j<m;j++){
                    score[j] += a[i][j];
                }
            }
        }

        rep(i,m){
            if(score[i]<x)ok = false;
        }

        if(ok){
            if(cost0>cost){
                cost0=cost;
            }
        }

    }
    
    if(cost0 == INF) cout << "-1" << endl;
    else cout << cost0 << endl;
    
    return 0;
}



