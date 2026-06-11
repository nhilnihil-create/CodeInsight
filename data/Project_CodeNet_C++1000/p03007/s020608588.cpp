#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    vector<int> minus;
    vector<int> plus;
    rep(i, N){
        if(A[i] < 0) minus.push_back(A[i]);
        else plus.push_back(A[i]);
    }
    sort(minus.begin(), minus.end());
    sort(plus.begin(), plus.end());
    if(minus.size() == 0){
        int ans = 0;
        for(int i = 1;i < plus.size();i++){
            ans += plus[i];
        }
        ans -= plus[0];
        cout << ans << endl;
        for(int i = 1;i < plus.size()-1;i++){
            cout << plus[0] << " " << plus[i] << endl;
            plus[0] -= plus[i];
        }
        cout << plus[plus.size()-1] << " " << plus[0] << endl;
    }else if(plus.size() == 0){
        int ans = 0;
        for(int i = 0;i < minus.size()-1;i++){
            ans += minus[i];
        }
        ans *= -1;
        ans += minus[minus.size()-1];
        cout << ans << endl;
        int endidx = minus.size() - 1;
        rep(i, endidx){
            cout << minus[endidx] << " " << minus[i] << endl;
            minus[endidx] -= minus[i];
        }
    }else{
        int ans = 0;
        rep(i, minus.size()) ans -= minus[i];
        rep(i, plus.size()) ans += plus[i];
        cout << ans << endl;
        for(int i = 1;i < plus.size();i++){
            cout << minus[0] << " " << plus[i] << endl;
            minus[0] -= plus[i];
        }
        rep(i, minus.size()){
            cout << plus[0] << " " << minus[i] << endl;
            plus[0] -= minus[i];
        }
    }
    return 0;
}
