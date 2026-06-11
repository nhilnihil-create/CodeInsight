#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
    string s;cin>>s;
    sort(all(s));
    if(s[0]==s[1]&&s[1]!=s[2]&&s[2]==s[3]){
        puts("Yes");
    }
    else puts("No");
    return 0;
}

