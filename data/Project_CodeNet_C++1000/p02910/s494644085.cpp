#include <bits/stdc++.h>
#define LL               long long
#define PB               push_back
using namespace std;
int main(){
    string s;cin>>s;
    for (long unsigned int i=0;i<s.length();i++){
        if ((i%2 && s[i]=='R') || ((i%2==0) && s[i]=='L')) {
            cout <<"No"; 
            return 0;
        }
    }
     cout <<"Yes"; 
}