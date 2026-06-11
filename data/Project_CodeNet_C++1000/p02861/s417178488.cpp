#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const ll INF = 1LL << 60;

int main() {
    
    int N;
    cin >> N ;
    int x[N];
    int y[N];

    rep(i,N){
        cin >> x[i] >> y[i];
    }

    double ans = 0;
    double rep = 0;

    vector<int> one_case;
    for (int i = 0; i < N; i++) { // one_case = {0,1,2,3,...n-1} とする
        one_case.emplace_back(i);
    }

    do {
        rep += 1;
        double len_sum = 0;
        for(int i=0;i<N-1;i++){
            double len = 0;
            len = pow(x[one_case[i]]-x[one_case[i+1]],2)+pow(y[one_case[i]]-y[one_case[i+1]],2);
            len = sqrt(len);
            len_sum += len;
        }
        ans += len_sum;


    } while (next_permutation(one_case.begin(), one_case.end()));

    ans = ans/rep;

    cout << std::fixed << std::setprecision(15) << ans << endl;

}