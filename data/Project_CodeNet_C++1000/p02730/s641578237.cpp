#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    string s;
    cin >> s;
    bool can = false;
    int n = s.size();
    int center = n/2;
    if(s.substr(0,center) == s.substr(center+1,center)) can = true;
    if(can) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}