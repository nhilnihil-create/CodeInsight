#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    int n;
    string s;
    cin >>n>>s;
    int ans=0;
    rep(i, n){
        if(s[i]=='A'&&i<n-2){
            if(s[i+1]=='B'&&s[i+2]=='C'){
                ans+=1;
            }
        }
    }
    cout<<ans<<endl;
}