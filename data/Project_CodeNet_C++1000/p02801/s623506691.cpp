#include <bits/stdc++.h> 
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    long long q(1);//cin>>q;
    while(q--){
        char a;cin>>a;
        cout<<(char)(a+1);
    }
    return 0;
}