#include<bits/stdc++.h>
using namespace std;
int main(){
string x[7]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
string s;cin>>s;
if(s=="SUN"||s=="MON"||s=="TUE"||s=="WED"||s=="THU"||s=="FRI"||s=="SAT"){
for(int i=0;i<7;i++)
    if(s==x[i])
        cout<<(7-i)<<endl;}
return 0;}
