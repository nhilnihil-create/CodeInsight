#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(n);i++)
#define chmax(x, y) { x = max(x, y); }
#define chmin(x, y) { x = min(x, y); }

int main(){
    string s,t;
    int cnt=0;
    cin>>s>>t;

    for(int i=0;i<s.size();i++){
        if(s[i]!=t[i]){
            t[i]=s[i];
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
    
}
