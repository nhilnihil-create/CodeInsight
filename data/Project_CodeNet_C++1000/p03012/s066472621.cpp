#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int n,i,s=0,t=0;
  cin >> n;
  vector<int> w(n);
  for(i=0;i<n;i++){
    cin >> w.at(i);
    s += w.at(i);
  }
  int md=s,d;
  for(i=0;i<n-1;i++){
    s -= w.at(i);
    t += w.at(i);
    if(s>t){
      d=s-t;
    }else{
      d=t-s;
    }
    md=min(md,d);
  }
  
  cout << md << endl;
}