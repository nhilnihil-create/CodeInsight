#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;
 ll N, ans=0;
string str;
 signed main(){
    cin >> N >> str;
    for(int i=0;i<str.size()-2;i++) {
        if(str[i]=='A'&&str[i+1]=='B'&&str[i+2]=='C') ans++;
    }
    cout << ans << endl;
    return 0;
}