#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<n; ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
#define ll long long int

string s;
bool iskai(int b, int e){
   while(b<e){
      if(s[b]!=s[e]) return false;
      b++;
      e--;
   }
   return true;
}

int main(){
   cin>>s;
   int n=s.size();

   if(iskai(0, n-1) && iskai(0, (n-1)/2-1) && iskai((n+3)/2-1, n-1))
      cout<<"Yes"<<endl;
   else
      cout<<"No"<<endl;

   return 0;
}
