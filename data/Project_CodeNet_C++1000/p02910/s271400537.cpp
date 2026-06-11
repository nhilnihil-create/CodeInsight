#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main() {
    string s;
    cin>>s;
    rep(i,s.length()){
        if(i%2!=0 && s[i]=='R'){
            cout<<"No"<<endl;
            return 0;
        }
        if(i%2==0 && s[i]=='L'){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
}