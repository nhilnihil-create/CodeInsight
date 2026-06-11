#include <bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  cin>>s;
 int i,c=0;
 for(i=0;i<s.size();i+=2)
 {
     if(s[i]!='R'&& s[i]!='U' && s[i]!='D'){
        c++;
        break;
     }

 }
 for(i=1;i<s.size();i+=2)
 {
     if(s[i]!='L' && s[i]!='U' && s[i]!='D'){
     c++;
     break;}

 }
 if(c>0) cout<<"No"<<endl;
 else cout<<"Yes"<<endl;
}
