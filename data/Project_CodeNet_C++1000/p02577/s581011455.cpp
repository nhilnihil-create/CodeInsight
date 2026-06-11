#include <bits/stdc++.h>
using namespace std;

int main(){
    string N = "";
    cin >> N;
    int mod = 9;
    int ans = 0;
    for (int i = 0; i < N.size(); i++){
        ans += N.at(i) - 48;
    }
    if (ans % mod == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}