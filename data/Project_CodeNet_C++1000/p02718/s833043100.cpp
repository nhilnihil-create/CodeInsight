#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
  int n,m,a[100];
  cin>>n>>m;
  int popu=0; double sum_a=0;
  rep(i,n){
    int A;
    cin>>A;
    a[i]=A;
    sum_a+=a[i];
  }
  rep(i,n){
    if(a[i] >= sum_a/(4*m)){
      popu++;
    }
  }
  if(popu>=m){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}
