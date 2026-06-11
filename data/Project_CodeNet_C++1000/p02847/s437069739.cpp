#include<bits/stdc++.h>
using namespace std;
int main(){
string s; cin>>s;
map<string,int> mp; 
mp["SUN"]=0; 
mp["MON"]=1; 
mp["TUE"]=2; 
mp["WED"]=3; 
mp["THU"]=4; 
mp["FRI"]=5; 
mp["SAT"]=6;
cout<<7-mp[s]<<endl; 
return 0;
} 