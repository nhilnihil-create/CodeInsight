#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long int
#define INF 1000000007
// cin.eof() 入力個数の問題
int main() {
    string s;
    cin >> s;
    int d[s.size() + 1], y[s.size() + 1];
    d[0] = 0;
    y[s.size()] = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '<') {
            d[i + 1] = d[i] + 1;
        } else {
            d[i + 1] = 0;
        }
        
    }
    for (int i = s.size()-1; i >= 0; i--) {
        if (s[i] == '>') {
            y[i] = y[i+1] + 1;
        } else {
            y[i] = 0;
        }
    }
    /*rep(i,s.size()+1){
        cout<<"d=="<<d[i]<<endl;
        cout<<"y=="<<y[i]<<endl;
    }*/
ll ans=0;
rep(i,s.size()+1){
    ans+=max(d[i],y[i]);
    //cout<<max(d[i],y[i])<<endl;
}
cout<<ans<<endl;
    return 0;
}
