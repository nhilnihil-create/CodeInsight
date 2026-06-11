#include <bits/stdc++.h>
#include <vector>
#include <string.h>

typedef long long ll;
typedef long double lg;

using namespace std;

int main(){

 string s;
 cin>>s;

 long long n = s.length();
 int flag=0;

  if(n < 2 || n%2 == 1){
    cout<<"No"<<endl;
     return 0; }


 for(int i=0;i<n-1;i+=2){

   if(s[i] == 'h' && s[i+1] == 'i')
    continue;
   else{
     flag = 1;
        break;}
 }

  if(flag == 0)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;

return 0;
}
