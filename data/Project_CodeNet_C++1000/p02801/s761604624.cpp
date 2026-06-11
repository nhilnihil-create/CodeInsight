#include<iostream>
#include<math.h>
using namespace std;

int main(){
    string s = "abcdefghijklmnopqrstuvwxyz";
    string t;
    cin>>t;
    if(t[0]=='z'){cout<<'a'; return 0;}
    for(int i=0;i<32;i++){
        if(t[0]==s[i]){cout<<s[i+1]; return 0;}
    }
    return 0;
}
