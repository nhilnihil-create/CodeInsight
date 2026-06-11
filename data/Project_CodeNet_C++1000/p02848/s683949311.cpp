#include<bits/stdc++.h>
using namespace std; 
int main(){
int n; cin>>n;
string s; cin>>s;
for(int i=0;i<s.length();i++){
s[i]=(char)(((s[i]-65)+n)%26+65);
}
cout<<s<<endl; 
return 0;
}