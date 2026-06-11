#include<bits/stdc++.h>
using namespace std;
    static const double pi = 3.141592653589793;
 typedef pair<int64_t,int64_t> P;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
int64_t a;
  cin>>a;
  vector<string>music(a);
  vector<int64_t>time(a);
  rep(i,a) cin>>music.at(i)>>time.at(i);
  string b;
  cin>>b;
  int x=0;
  int64_t y=0;
  rep(i,a){
  if(x==1) y+=time.at(i);
    if(music.at(i)==b) x=1;
  
  }
  
  cout<<y;
  
  
  
}