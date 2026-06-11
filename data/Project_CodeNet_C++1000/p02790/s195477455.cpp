#include <bits/stdc++.h>

 using namespace std;
 char var[110];
 int main(){
 int a,b;
   scanf("%d%d",&a,&b);
 for(int i=0;i<b;i++)
   var[i]='0'+a;
 string L=var;
 for(int i=0;i<a;i++)
   var[i]='0'+b;
var[a]=0;
string R=var;
printf("%s\n",min(L,R).c_str());
}