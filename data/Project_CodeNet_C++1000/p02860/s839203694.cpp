#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main() {
    int n;
    cin>>n;
    vector<char> s(n);
    rep(i,n){
        cin>>s[i];
    }
    if(n%2!=0){
        cout<<"No"<<endl;
        return 0;
    }
    rep(i,n/2){
        char s1=s[i];
        char s2=s[n/2+i];
        if(s1!=s2){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
}