#include <bits/stdc++.h>          
using namespace std;
typedef long long ll;

int main() {
    ll N, M, X;
    cin >> N >> M >> X;
    // vector<vector<ll>> vec(N,vector<ll>(M+1));
    vector<ll> C(N);
    vector<vector<ll>> A(N,vector<ll>(M));
    for (int i=0; i<N; i++) {
        cin >> C[i];
        for (int j=0; j<M; j++) {
            cin >> A[i][j];
        }
    }

    vector<ll> nedan;
    for (int s=0; s<(1<<N); s++) {

        vector<ll> rikaido(M,0);
        ll nedan_temp = 0;

        for (int i=0; i<N; i++) {
            if ((s>>i)&1) {
                nedan_temp += C[i];
                for (int j=0; j<M; j++) {
                    rikaido[j] += A[i][j];
                }
            }
        }

        int count = 0;
        for (int j=0; j<M; j++) {
            if (rikaido[j]>=X) {
                count++;
            }
        }

        if (count==M) {
            nedan.push_back(nedan_temp);
        }

    }

    ll ans;
    if (nedan.size()==0) {
        ans = -1;
    }
    else {
        sort(nedan.begin(),nedan.end());
        ans = nedan[0];
    }
    
    cout << ans << endl;

    /*
    sort(vec.begin(),vec.end(),[](const vector<ll> &alpha,const vector<ll> &beta){return alpha[0] < beta[0];});
    
    vector<ll> rikaido(M,0);
    ll ans = 0;
    ll flag = 0;
    for (int i=0; i<N; i++) {
        ans += vec[i][0];
        ll count = 0;
        for (int j=0; j<M; j++) {
            rikaido[j] += vec[i][j+1];
            if (rikaido[j]>=X) {
                count++;
            }
        }
        if (count==M) {
            flag = 1;
            break;
        }
    }
    if (flag==0) {
        ans = -1;
    }
    cout << ans << endl;
    */
}