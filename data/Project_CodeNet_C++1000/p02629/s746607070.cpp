#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main(void){
    ll n;
    cin >> n;
    string ans = "";
    while(n){
        int ama = n % 26;
        if(ama == 0) ama += 26;
        ans = char('a' + (ama - 1)) + ans;
        if(n % 26 == 0) n--;
        n /= 26;
    }
    cout << ans << endl;
    return 0;
}