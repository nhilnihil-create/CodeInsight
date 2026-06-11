#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

int main(){
    int n;
    string s, t;
    cin >> n;
    cin >> s >> t;

    for(int i = 0; i < n; i++){
        cout << s[i] << t[i];
    }
    cout << endl;
   return 0;
}