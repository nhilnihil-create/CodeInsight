#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    int n = s.length();
    string former = s.substr(0,n/2);
    reverse(s.begin(),s.end());
    string latter = s.substr(0,n/2);
    //cout << former << " " << latter << endl;

    int ans = 0;
    vector<int> d(n);
    for(int i=0; i<n/2; i++){
        if(former[i] != latter[i]) ans += 1;
    }
    cout << ans << endl;
    return 0;
}