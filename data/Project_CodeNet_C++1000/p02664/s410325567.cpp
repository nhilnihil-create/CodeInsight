#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1LL<<60;
const ll mod=1000000007;
int main(void){
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='?') s[i]='D';
        cout<<s[i];
    }
    cout<<endl;
}