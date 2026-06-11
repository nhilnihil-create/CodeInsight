#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s; cin >>s;

    ll sum = 0;
    for(int i = 0; s[i]; i++){
        sum += (s[i]-'0');
    }

    cout <<(sum%9 == 0? "Yes" : "No") <<endl;

    return 0;
}
