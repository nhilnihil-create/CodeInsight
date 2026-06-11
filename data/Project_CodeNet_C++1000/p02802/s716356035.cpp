#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, string>> ps(m);
    rep(i, m){
        int a;
        string b;
        cin >> a >> b;
        ps[i] = make_pair(a, b);
    }
    vector<int> ac(n + 1, 0), wa(n + 1 ,0);
    rep(i, m){
        if(ps[i].second == "AC"){
            if(ac[ps[i].first] == 0){
                ac[ps[i].first]++;
            }
        }else{
            if(ac[ps[i].first] == 0){
                wa[ps[i].first]++;
            }
        }
    }
    int a = 0, w = 0;
    rep(i, n + 1){
        if(ac[i] != 0){
            a += ac[i];
            w += wa[i];
        }
    }
    cout << a << " " << w << endl;
    return 0;
}