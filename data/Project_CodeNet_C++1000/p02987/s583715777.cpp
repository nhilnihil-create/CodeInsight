#include <bits/stdc++.h>
#define LL               long long
#define PB               push_back
using namespace std;
int main(){
    string s;cin>>s;
    for (int i=0;i<4;i++){
        if (count(s.begin(),s.end(),s[i])!=2){
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
}