#include<bits/stdc++.h> 
using namespace std; 
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL); 
  int n;
  cin>>n;
  vector<long long int> v(n+1,1);
  for(int i=2;i<=n;i++){
    for(int j=i;j<=n;j+=i){
      v[j]++;
    }
  }
  long long sum=0;
  for(int i=1;i<=n;i++){
    sum+=v[i]*i;
  }
  cout<<sum<<endl;

  

} 