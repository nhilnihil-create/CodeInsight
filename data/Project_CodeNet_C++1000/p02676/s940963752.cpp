#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    int k;
    cin>>k;
    string s;
    cin>>s;
    string ans="";
    int i;
    for(i = 0; i < k && i < s.size(); i++){
        ans += s[i];
    }
    if(s.size() > k) cout<<ans+"...";
    else cout<<ans;
    return 0;
}