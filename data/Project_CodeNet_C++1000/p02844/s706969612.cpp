#include <bits/stdc++.h>
#define rep(i, n)  for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int n;
    string s;
    cin >> n >> s;
    set<string> secrets;
    rep(i, 10){
        int pos1 = s.find(to_string(i));
        if(pos1 == string::npos || pos1 > n-3) continue;
        string substr1 = s.substr(pos1+1);
        rep(j, 10){
            int pos2 = substr1.find(to_string(j));
            if(pos2 == string::npos || pos2 > n-2) continue;
            string substr2 = substr1.substr(pos2+1);
            rep(k, 10){
                if(substr2.find(to_string(k)) != string::npos){
                    secrets.insert(to_string(i) + to_string(j) + to_string(k));
                }
            }
        }
    }
    cout << secrets.size() << endl;
}
