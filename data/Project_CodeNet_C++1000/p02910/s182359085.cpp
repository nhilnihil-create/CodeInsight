#include <bits/stdc++.h>
using namespace std;
int main()
{
    bool chk=true;
 string S;
 cin >> S;
 for(int i=0; i<S.size(); i++)
 {
     if(i%2==0&&(!(S.at(i)=='R'||S.at(i)=='U'||S.at(i)=='D')))
     {
         chk=false;
     }
    if(i%2==1&&(!(S.at(i)=='L'||S.at(i)=='U'||S.at(i)=='D')))
     {
         chk=false;
     }
 }
 if(chk)
 {
     cout <<"Yes"<<endl;
 }
 else
 {
     cout<<"No"<<endl;
 }
 
}