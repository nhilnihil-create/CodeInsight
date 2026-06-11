#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll=long long;

int main(){
 int count=0;
 string s, t;
  
 cin >> s;
 cin >> t;
  
 rep(i,s.size()){
   if(s.at(i)!=t.at(i)){
     s.at(i)=t.at(i);
     count++;
   }
 }
  
 cout << count << endl;

}
