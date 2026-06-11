#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void p(vector<int> A){rep(i,A.size()){cout << A[i] << " ";}cout << "\n";}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n-1);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    rep(i,n-1) cin >> c[i];
    int ans = b[a[0]-1];
    for(int i = 1; i < n; i++){
        ans += b[a[i]-1];
        if (a[i] == a[i-1]+1){
            ans += c[a[i]-2];
        }
    }
    cout << ans;
}