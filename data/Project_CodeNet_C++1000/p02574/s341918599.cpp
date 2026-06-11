#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int gcd(int a,int b){
  if(b==0){
    return a;
  }
  else{
    return gcd(b,a%b);
  }
}
int main(){
  int i,j,n;
  cin >> n;
  int a[1000010],b[1000010];
  for(i=0;i<n;i++){
    cin >> a[i];
    b[i]=a[i];
  }
  vector<int> x(1000010);
  for(i=0;i<=1000000;i++){
    x[i]=i;
  }
  for(i=2;i*i<=1000000;i++){
    if(x[i]!=i){
      continue;
    }
    for(j=i*2;j<=1000000;j=j+i){
      x[j]=i;
    }
  }
  int res=0;
  vector<int> c(1000010,0);
  for(i=0;i<n;i++){
    vector<int> d;
    while(a[i]>1){
      if(c[x[a[i]]]==1){
        res=1;
        break;
      }
      d.push_back(x[a[i]]);
      a[i]=a[i]/x[a[i]];
    }
    for(j=0;j<d.size();j++){
      c[d[j]]=1;
    }
  }
  if(res==0){
    cout << "pairwise coprime" << endl;
    return 0;
  }
  for(i=0;i<n;i++){
    a[i]=b[i];
  }
  int ans=gcd(a[0],a[1]);
  for(i=2;i<n;i++){
    ans=gcd(ans,a[i]);
  }
  if(ans==1){
    cout << "setwise coprime" << endl;
  }
  else{
    cout << "not coprime" << endl;
  }
}