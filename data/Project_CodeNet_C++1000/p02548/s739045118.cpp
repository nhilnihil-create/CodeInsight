#include<bits/stdc++.h>
//#include<atcoder/all>

typedef long long ll;

using namespace std;

int main(){
    int n;
    cin >> n;
    ll ans = 0;
    for(int i = 1;i < n;i ++){
        ans += (n-1)/i;
    }
    cout << ans << endl;
    return 0;
}