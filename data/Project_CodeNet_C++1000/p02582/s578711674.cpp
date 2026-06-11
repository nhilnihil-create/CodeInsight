#include <bits/stdc++.h>
using namespace std;
string s;
long long r,k;
int main(){
cin>>s;
for(int i=0;i<3;i++){
    if(s[i]=='R')k++;
}
if(k==3)cout<<k;
else{


for(int i=0;i<3;i++){
if(s[i]==s[i+1]&&s[i]=='R'){
                r+=2;break;}
        else if(s[i]=='R'&&s[i+1]!='R'){
                r++;break;
        }

}
 cout<<r;}

    return 0;}
