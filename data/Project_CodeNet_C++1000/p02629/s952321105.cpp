#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n, tmp;
    string s="abcdefghijklmnopqrstuvwxyz", ans="";
    cin >> n;
    tmp=n;
    while(tmp>0){
        tmp--;
        ans+=s[(tmp%26)];
        tmp/=26;
    }
    reverse(ans.begin(), ans.end());
    cout << ans <<endl;
}