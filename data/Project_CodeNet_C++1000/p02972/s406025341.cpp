#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int n,i,j,s,sum=0;
  cin >> n;
  vector<int> a(n),b(n,0);
  for(i=0;i<n;i++){
    cin >> a.at(i);
  }
  for(i=n-1;i>=0;i--){
    s=0;
    for(j=1;j<=n/(i+1);j++){
      s += b.at(j*(i+1)-1);
    }
    b.at(i)=(s+a.at(i))%2;
    sum += b.at(i);
  }
  cout << sum << endl;
  for(i=0;i<n;i++){
    if(b.at(i)==1){
      cout << i+1 << ' ';
    }
  }
}