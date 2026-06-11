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
cin>>a>>p;
cin>>u;
int n = s.length(),m=t.length(),v=u.length();
int x1,x2,x3;
char x[n+1],y[m+1],z[v+1];
strcpy(x,s.c_str());strcpy(y,t.c_str());strcpy(z,u.c_str());
x1=lower_case(x,n,b);
x2=lower_case(y,m,b);
x3=lower_case(z,v,b);
if(x1==0&&x2==0&&x3==0&&n<=10&&m<=10&&n>=1&&m>=1&&s!=t&&(s==u||t==u)&&a>=1&&p>=1&&a<=10&&p<=10){
    if(s==u)
        cout<<(a-1)<<" "<<p<<endl;
    else if(t==u)
        cout<<a<<" "<<(p-1)<<endl;
}


return 0;}
