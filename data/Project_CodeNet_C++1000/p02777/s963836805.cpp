
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    string s, t, u;
    int a, b;
    cin >> s >> t >> a >> b >> u;
    if(s == u){
        cout << a-1 << " " << b << endl;
    }
    else{
        cout << a << " " << b-1 << endl;
    }

}