#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef map<string, int> msi;

int main(){
    int n, m; cin >> n >> m;
    vector<int> v(n);
    vector<int> acess;
    vector<bool> flag(n, false);
    rep(i, m){
        int s, c; cin >> s >> c;
        s--;
        if(!flag.at(s) || c == v.at(s)) {
            v.at(s) = c;
            acess.push_back(s);
            flag.at(s) = true;
        }
        else{
            cout << "-1" << endl;
            return 0;
        }
        if(n > 1 && v.at(0) == 0 && flag.at(0)){
            cout << "-1" << endl;
            return 0;
        }
    }
    int x = pow(10, n);
    int i = pow(10, n-1);
    if(n == 1) i = 0;
    while(i < x){
        bool f = true;
        string s = to_string(i);
        for(auto j : acess){
            if(v.at(j) != s[j] - '0'){
                f = false;
            }
        }
        if(f) {
            cout << i << endl;
            return 0;
        }
        i++;
    }

    return 0;
}
