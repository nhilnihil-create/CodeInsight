#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n;
  cin >> n;
  vector<int>a(n+1);
  vector<int>b(n);
  for(int i=0;i<=n;i++){
    cin >> a.at(i);
  }
  for(int i=0;i<n;i++){
    cin >> b.at(i);
  }
  long long ans=0;
  for(int i=0;i<n;i++){
    if(a.at(i)>=b.at(i)){
      ans+=b.at(i);
      a.at(i)-=b.at(i);
      b.at(i)=0;
    }
    else if(a.at(i)<b.at(i)){
      ans+=a.at(i);
      b.at(i)-=a.at(i);
      a.at(i)=0;
    }
    if(b.at(i)>a.at(i+1)){
      ans+=a.at(i+1);
      a.at(i+1)=0;
    }
    if(b.at(i)>0&&b.at(i)<=a.at(i+1)){
      ans+=b.at(i);
      a.at(i+1)-=b.at(i);
    }
  }
  cout << ans << endl;
}
      