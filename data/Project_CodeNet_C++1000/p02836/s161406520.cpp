#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int c=0,x=s.length();
    for(int i=0;i<(x/2);i++)
    if(s[i]!=s[x-i-1])
    c++;
    cout<<c;
}