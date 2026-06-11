
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    for(int i=0; i<n; i++){
        cout << s[i] << t[i];
    }
    cout << endl;
}