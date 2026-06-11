#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e7+5;
const ll inf=2e18;
const int mod=998244353;
string s;
int main(){
    cin>>s;
    if(s[s.length()-1]=='s')s+="es";
    else s+='s';

    cout<<s<<endl;
    return 0;
}
