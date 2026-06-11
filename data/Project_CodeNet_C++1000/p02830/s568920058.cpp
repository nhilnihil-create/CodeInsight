#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const ll INF = 1LL<<60;
/////////////////////////////////
int main(){
    int n;
    cin>>n;
    string s, t;
    cin >> s >> t;
    rep(i,n){
        cout << s[i] << t[i];
    }
    cout << endl;
}