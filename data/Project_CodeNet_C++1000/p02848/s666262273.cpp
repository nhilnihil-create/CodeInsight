#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    
    size_t l=s.length();
    
    rep(i,l){
        int num=s[i]-'A';
        char c=(num+n)%26+'A';
        cout<<c;
    }
    
    return 0;
}