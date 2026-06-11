#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    string s;
    cin>>s;
    int ans=0;
    if(s.size()%2==1){
        rep(i, (s.size()-1)/2){
            if(s[i]!=s[s.size()-i-1]) ans++;
        }
    }else{
        rep(i, s.size()/2){
            if(s[i]!=s[s.size()-i-1]) ans++;
        }
    }
    cout<<ans<<endl;
}