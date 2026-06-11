#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll k; cin >>k;
    string s = string(1000000, '7');

    ll ans = -1, r = 0;
    for(int i = 0; i<s.length(); i++){
        r = ((r*10)%k + 7)%k;
        if(!r){
            ans = i+1;
            break;
        }
    }

    cout <<ans <<endl;

    return 0;
}
