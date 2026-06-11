#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    int total = 0;
    vector<int> a(3);
    string ans;
    for(int i = 0; i < 3; i++) cin >> a[i];
    for(int i = 0; i < 3; i++) total += a[i];
    if(total <= 21) ans = "win";
    else ans = "bust";
    cout << ans << endl;
    return 0;
}