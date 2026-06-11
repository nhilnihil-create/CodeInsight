#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N;
    cin >>N;
    map<string,int> mp;
    for(int i=0;i<N;i++){
     string s;
     cin >>s;
     mp[s]++;
   }  
   int mx=0;
   for(auto p :mp){
       mx=max(mx,p.second);
   }
   for(auto p : mp){
       if(p.second != mx) continue;
       cout <<p.first <<endl;
   }

}