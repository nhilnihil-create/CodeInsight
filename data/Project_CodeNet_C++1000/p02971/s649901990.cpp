
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

//前処理で西と東の予選をO(n)でやっておいて決勝をO(1)で行うというイメージ
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);

    vector<int> lm(n); //iより左にあるものたちの中でのmax
    vector<int> rm(n); //iより右にあるものたちの中でのmax

    for(int i=1;i<n;i++){
        lm[i] = max(lm[i-1],a[i-1]);
    }
    //a、rmのインデックスが最大n-1なので、それより1左にずらしてn-2
    for(int i=n-2; i>=0;i--){
        rm[i] = max(rm[i+1],a[i+1]);
    }
    rep(i,n) cout << max(lm[i],rm[i]) << endl;

}