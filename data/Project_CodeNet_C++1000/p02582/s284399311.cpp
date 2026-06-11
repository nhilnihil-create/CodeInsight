#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
void solve(){
    int n=0,m=0;
    string s;
    cin>>s;
    for (int i = 0; i < 3; ++i) {
        if (s[i]=='R') n++;
        else n=0;
        if (m<n)m=n;
    }
    cout<<m<<endl;
}
int main(){
    int _=1;
    while(_--){
        solve();
    }
}