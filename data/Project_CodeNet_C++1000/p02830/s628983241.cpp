#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void p(vector<int> A){rep(i,A.size()){cout << A[i] << " ";}cout << "\n";}

int main(){
    int n;
    string s,t;
    cin >> n >> s >> t;
    string ans="";
    rep(i,n){
        ans += s[i];
        ans += t[i];
    }
    cout << ans;
}