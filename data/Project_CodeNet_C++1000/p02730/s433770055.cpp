#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
#include<string.h>
using namespace std;
int main(){
string s,a;
int c;
cin>>s;
a=s;
reverse(a.begin(),a.end());
if(a==s){
    c=1;
}
if(c==1){
    int l=s.length();
    int m=l/2;
    for(int i=0;i<m;i++)
    if(s[i]!=s[m+i+1]){
        c=0;
    }
}
if(c==0)
    cout<<"No";
else
    cout<<"Yes";


}