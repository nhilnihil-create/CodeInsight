#include<bits/stdc++.h>
using namespace std;

int main()
{
   string s;
   cin>>s;
   int l=s.size();
   if(s[l-1]=='3')
    cout<<"bon"<<endl;
   else if(s[l-1]=='0'||s[l-1]=='1'||s[l-1]=='6'||s[l-1]=='8')
    cout<<"pon"<<endl;
   else if(s[l-1]=='2'||s[l-1]=='4'||s[l-1]=='5'||s[l-1]=='7'||s[l-1]=='9')
   cout<<"hon"<<endl;
    return 0;
}

