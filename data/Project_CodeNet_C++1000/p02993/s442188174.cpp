#include <bits/stdc++.h>
using namespace std;
string s;
int k;
int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
cin>>s;
for(int i=0;i<4;i++){
    if(s[i]==s[i+1])k++;
}
if(k>=1)cout<<"Bad";
else cout<<"Good";
return 0;}

