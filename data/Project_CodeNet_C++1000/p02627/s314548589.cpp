#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


void solve(){
    char ch;
    cin>>ch;
    if(isupper(ch)) cout<<"A";
    else cout<<"a";


}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int q;
    q=1;
    // cin>>q;
    while(q--) solve();


    return 0;
}