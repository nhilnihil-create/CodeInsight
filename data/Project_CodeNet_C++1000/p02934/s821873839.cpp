#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
 ll N;
  cin>>N;
  double sum=0;
  for(ll i=0;i<N;i++) {
double A;
    cin>>A;
    sum+=1/A;
  }
  
  cout<<fixed<<setprecision(7);
  cout<<1/sum<<endl;
}
