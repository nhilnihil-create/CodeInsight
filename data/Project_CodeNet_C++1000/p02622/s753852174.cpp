#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
#include<string.h>
using namespace std;
int main(){
int c=0,i,l;
string s,t;
cin>>s;
cin>>t;
l=s.length();
for(i=0;i<l;i++){
    if(s[i]!=t[i])
        c++;
}
cout<<c;
}
