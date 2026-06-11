#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0; i < (int)(n); i++)

int main(void){
    string s,t;
    cin>>s;
    cin>>t;
    int count=0;
    int size=s.size();
    rep(i,size){
        if(s[i]!=t[i])count++;
    }
    cout<<count<<endl;
}