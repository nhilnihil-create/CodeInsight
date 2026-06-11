#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    string S;
    cin >> S;
    vector<string> a={"SUN","MON","TUE","WED","THU","FRI","SAT","SUN"};
    rep(i,7){
        if(S==a.at(i)){
            cout << 7-i << endl;
            break;                }
    }
}