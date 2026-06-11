#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793
 
 
   
int main(){
  int n,m;
  cin >> n >>m;
  VI p(m);
  vector<string> s(m);
  rep(i,m)cin >> p.at(i) >> s.at(i);
  map<int ,int> cnt;
  int wrg=0;
  set<int> crt;
  for(int i=1;i<=n;i++){
    cnt[i]=0;
  }
  rep(i,m){
    if(s.at(i)=="AC" && !crt.count(p.at(i))){
      crt.insert(p.at(i));
      wrg+=cnt.at(p.at(i));
    }
    else if(s.at(i)=="WA" && !crt.count(p.at(i))){
    cnt.at(p.at(i))++; 
    }
  }
  int ac=crt.size();
  cout << ac << " " << wrg << endl;
} 
    