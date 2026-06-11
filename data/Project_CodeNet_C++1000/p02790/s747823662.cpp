#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); i++)
using namespace std;
using ll = long long;

int main(void) {
    int a,b; cin >> a >> b;
    string ans; 
    if(a <= b) {
        for(int i=0; i<b; i++) ans+=to_string(a);
    }
    else {
     for(int i=0; i<a; i++) ans+=to_string(b);
    }
    cout << ans << endl;
}