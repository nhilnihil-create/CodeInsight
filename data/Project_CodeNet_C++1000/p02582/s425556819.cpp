#include<bits/stdc++.h>

using namespace std;

int main(){
   string s;
   cin>>s;

   int xx=0, mx=-1;
   for(char x: s){
        if(x=='R') xx++;
        else { xx=0;}
        mx=max(mx, xx);
   }
   cout<<(mx ==-1 ? 0 : mx);
}
