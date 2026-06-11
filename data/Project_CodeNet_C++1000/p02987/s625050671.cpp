#include<bits/stdc++.h>
using namespace std;
int main(void){
string s;cin>>s;
char x[5];
strcpy(x,s.c_str());
sort(x,x+4);
cout<<((x[0]==x[1])&&(x[2]==x[3]&&x[0]!=x[3])?"Yes":"No")<<endl;
return 0;}
