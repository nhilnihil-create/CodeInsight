#include<bits/stdc++.h>
using namespace std;
int lower_case(char x[],int n,bool b){
    for(int i=0;i<n;i++)
        if(x[i]>=65&&x[i]<=90)
            {b=1;break;}
return b;}

int main(){
string s,t,u;
int a,p;
bool b = 0;
cin>>s>>t;
int n = s.length(),m=t.length();
int x1,x2;
char x[n+1],y[m+1];
strcpy(x,s.c_str());strcpy(y,t.c_str());
x1=lower_case(x,n,b);
x2=lower_case(y,m,b);
if(x1==0&&x2==0&&n<=100&&m<=100&&n>=1&&m>=1){
    cout<<t+s<<endl;
}


return 0;}
