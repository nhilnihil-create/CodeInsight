#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<string>
using namespace std;
int main()
{

string s;
cin>>s;
int flag=0,flag1=0,temp=0,b,m;
int a=s.size()-1; ///4
for(int i=0;i<s.size()/2;i++)
{
    if(s[i]==s[a-i])
    {
        continue;
    }
    else{temp++;
}
}
b=(a-1)/2;///1
for(int i=0;i<=b;i++)
{
    if(s[i]==s[b-i])
    {
        continue;
    }
    else{flag++;
}
}

    m=(a+3)/2;
      for(int i=m;i<=a;i++)
{
    if(s[i]==s[a-i])
    {
        continue;
    }
    else{flag1++;
}
    }
    if(temp==0 && flag==0 && flag1==0)
        cout<<"Yes"<<endl;

else
cout<<"No"<<endl;
     return 0;
}
