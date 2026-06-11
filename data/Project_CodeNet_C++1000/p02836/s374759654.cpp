#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int ans;
int main(void){
    string s; cin>>s;
    if(s.size()%2==0){
        for(int i=0;i<s.size()/2;i++){
            if(s[i]!=s[s.size()-1-i]) ans++;
        }
    }else{
        for(int i=0;i<s.size()/2;i++){
            if(s[i]!=s[s.size()-1-i]) ans++;
        }
    }
    cout<<ans<<endl;

}
