#include<bits/stdc++.h>
using namespace std;
int main(void){
string s;cin>>s;
char x[5];
strcpy(x,s.c_str());
for(int i=0;i<3;i++)
    if(x[i]==x[i+1])
        {cout<<"Bad"<<endl;return 0;}
cout<<"Good"<<endl;

return 0; }
