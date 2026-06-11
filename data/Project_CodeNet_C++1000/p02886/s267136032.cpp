#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void p(vector<int> A){rep(i,A.size()){cout << A[i] << " ";}cout << "\n";}

int main(){
    int n;
    cin >> n;
    vector<int> d(n);
    rep(i,n)cin >> d[i];
    int ans = 0;
    rep(i,n){
        rep(j,n){
            if(i != j){
                ans += d[i]*d[j];
               }
        }
    }
    cout << ans/2;
}
