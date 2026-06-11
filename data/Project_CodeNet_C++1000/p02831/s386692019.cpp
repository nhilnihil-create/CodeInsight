#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  long long int A;
  long long int B;
  long long int sum = 0;
  cin>>A;
  cin>>B;
  for(int i = 1;i <= B;i++){
    if((A * i) % B == 0){
      sum = A * i;
      break;
    }
  }
  cout<<sum<<'\n';
}