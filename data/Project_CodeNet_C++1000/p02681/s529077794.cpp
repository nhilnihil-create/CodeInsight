#include <bits/stdc++.h>
using namespace std;

int main() {

   string st1,st2;
   cin>>st1>>st2;
   int s1=st1.size();
   int s2=st2.size();
   int c=0;
  // cout<<s1;
   for(int i=0;i<s2;i++){
    if(st1[i]==st2[i]){
         c++;
         // cout<<c;
    }

    else if(st1[i]!=st2[i] && c==s1){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
        break;
    }
   }


}
