#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string s, int start, int end){
    for(int i = start;i<=end/2;++i){
        if(s[i] != s[end-i]){
            return false;
        }
    }
    return true;
}

int main(){
    string s;
    cin>>s;
    int n = s.length();
    if(isPalindrome(s,0,n-1) && isPalindrome(s,0,(n-1)/2-1) && isPalindrome(s,(n+3)/2-1,n-1)  ){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
    return 0;
}