#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    string s;
    cin>>s;
    int c=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='R'){
            if(i%2!=0){
                c++;
                break;
            }
        }
        if(s[i]=='L'){
            if(i%2==0){
                c++;
                break;
            }
        }
    }
    if(c==0)
        cout<<"Yes";
    else
        cout<<"No";
}
