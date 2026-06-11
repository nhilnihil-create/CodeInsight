#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
int main(){
 string a,b;
 map<string ,int> mp;
 cin>>a;
 cin>>b;
 int aa,bb;
 cin>>aa>>bb;
 string t;
 cin>>t;

 mp[a] = aa;
 mp[b] = bb;
 mp[t]--;
 
 
  cout<<mp[a]<<" "<<mp[b];
  cout<<"\n";
return 0;
}
