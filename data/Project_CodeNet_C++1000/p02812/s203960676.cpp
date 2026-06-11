#include<bits/stdc++.h>
using namespace std;
int main(){

int n,cnt=0;
cin>>n;
string s;
cin>>s;
for(int i=0; i<s.length()-2;i++){

    if(s[i]=='A' && s[i+1]=='B' && s[i+2]=='C')
        cnt++;
}

cout<<cnt<<endl;



return 0;
}
