#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int n;
vector<int> l;

bool isok(int a,int b, int c){
  if(l[a]+l[b]>l[c])return true;
  else return false;
}

    
int nibutan(int a, int b){
  int ok=b,ng=n;
  while(ng-ok>1){
    int naka=(ng+ok)/2;
    if(isok(a,b,naka))ok=naka;
    else{
      ng=naka;
    }
  }
    return ok-b;
}
   
 int main(){
  cin>>n;
   l.resize(n);
  rep(i,n){
    cin>>l[i];
  }
   ll ans=0;
  sort(l.begin(),l.end());
  for(int a=0;a<n;a++){
    for(int b=a+1;b<n;b++){
      ans+=nibutan(a,b);
    }
  }
  cout<<ans<<endl;
 }

