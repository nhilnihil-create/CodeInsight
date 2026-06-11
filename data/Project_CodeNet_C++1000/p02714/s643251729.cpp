#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    long r = 0;
    long g = 0;
    long b = 0;
    for(int i=0;i<s.length();i++){
        if(s[i] == 'R')r++;
        else if(s[i]=='G')g++;
        else b++;
    }
    long tmp = r*g*b;
    int maxLen = s.length();
    for(int i=1;i<4000;i++){
        for(int j=0;j<maxLen;j++){
            if(j+i+i >= maxLen)break;

            if(s[j] != s[j+i] && s[j] != s[j+i+i] && s[j+i] != s[j+i+i])tmp--;
        }
    }
    cout << tmp << endl;
}