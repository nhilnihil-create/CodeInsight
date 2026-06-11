#include<bits/stdc++.h>
using namespace std;
int main(){
int n; cin>>n; 
string s; cin>>s;
char prev='0';
int cnt=0;
for(char c:s){ if(c!=prev) cnt++; prev=c; }
cout<<cnt<<endl;
return 0;
}