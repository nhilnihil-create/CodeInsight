#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    char tmp='A';
    int ans=0;
    rep(i,n){
        if(tmp!=s[i]){
            ans++;
            tmp=s[i];
        }
    }

    cout<<ans<<endl;
}