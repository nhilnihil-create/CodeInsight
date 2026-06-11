#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<int> u(N);
  for(int &i:u)
    cin>>i;
  sort(u.begin(),u.end());
  long double j=u[0];
  for(int i=1;i<N;i++)
    j=(j+u[i])/2;
  cout<<fixed<<setprecision(16)<<j<<endl;
}