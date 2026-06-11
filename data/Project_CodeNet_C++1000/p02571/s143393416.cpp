#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
ll n,cnt=0;
string s1,s2;
int main() {
 //   freopen("../in.in", "r", stdin);
//    freopen("../out.out","w",stdout);
    ios::sync_with_stdio(false);
    ll t, i, j = 0;
    ll m, x, y,k;
    cin>>s1>>s2;
    ll maxn=0;
    for(i=0;i<=s1.length()-s2.length();i++){
        cnt=0;
        for(j=0;j<s2.length();j++){
            if(s1[i+j]==s2[j]) cnt++;
        }
        maxn=max(maxn,cnt);
    }
    cout<<s2.length()-maxn<<endl;
    return 0;
}