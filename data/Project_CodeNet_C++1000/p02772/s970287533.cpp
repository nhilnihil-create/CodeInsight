#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int n;
    cin >> n;
    vector<int> odd, none;
    // bool ans = true;
    rep(i,n){
        int a;
        cin >> a;
        if(a % 2 == 0){
            if(a % 3 == 0 || a % 5 == 0) odd.push_back(a);
            else none.push_back(a);
        }
    }
    // if(odd.empty()) ans = false;
    if(none.empty()) cout << "APPROVED" << endl;
    else cout << "DENIED" << endl;
    return 0;
}