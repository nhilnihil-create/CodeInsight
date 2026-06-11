#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793
 
 
   
int main(){
 int  n;
 cin >>n;
 vector<string> s(n);
 rep(i,n)cin >> s.at(i);
 map<string,int> w;
 rep(i,n){
   if(w.count(s.at(i))){
     w.at(s.at(i))++;
   }
   else w[s.at(i)]=1;
 }
 int cnt=0;
 rep(i,n){
    cnt=max(cnt,w.at(s.at(i)));
 }
 for(auto p : w){
   auto k=p.first;
   auto v=p.second;
   if(cnt==v)cout << k << endl;
 }
} 
    