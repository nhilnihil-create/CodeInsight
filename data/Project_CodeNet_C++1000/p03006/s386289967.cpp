#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int n,i,j,k;
  cin >> n;
  if(n==1){
    cout << 1 << endl;
    return 0;
  }
  vector<ll> x(n),y(n);
  vector<pair<ll,ll>> p(n*(n-1)/2);
  for(i=0;i<n;i++){
    cin >> x.at(i) >> y.at(i);
  }
  
  k=0;
  for(i=0;i<n-1;i++){
    for(j=i+1;j<n;j++){
      p.at(k).first=x.at(j)-x.at(i);
      p.at(k).second=y.at(j)-y.at(i);
      if(p.at(k).first<0||(p.at(k).first==0&&p.at(k).second<0)){
        p.at(k).first *= -1;
        p.at(k).second *= -1;
      }
      k++;
    }
  }
  
  sort(p.begin(),p.end());
  
  int c=1,maxc=0;
  //cout << p.at(0).first << ' ' << p.at(0).second << endl;
  for(k=1;k<n*(n-1)/2;k++){
    //cout << p.at(k).first << ' ' << p.at(k).second << endl;
    if(p.at(k-1)==p.at(k)){
      c++;
    }else{
      maxc=max(maxc,c);
      c=1;
    }
  }
  maxc=max(maxc,c);
  cout << n-maxc << endl;
}