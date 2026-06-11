#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;
const long long MOD=1e09+7;



#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,m,n) for(int i=m;i<n;i++)
#define ALL(v) v.begin(), v.end()





int main(){
  

  int n;
  cin>>n;
  vi data(n+1);
  for (int i=1;i<=n;i++){
    int tmp;
    cin>>tmp;
    data.at(i)=tmp;
  }
  
  vi answer(n+1,0);
  
  for (int i=n;i>=1;i--){
    int sum=0;
    for (int j=2*i;j<=n;j+=i){
      sum+=answer.at(j);
      sum%=2;
    }
    answer.at(i)=abs(data.at(i)-sum)%2;
  }
  
  int count=0;
  for (int i=1;i<=n;i++){
    count+=answer.at(i);
  }
  
  cout<<count<<endl;
  for (int i=1;i<=n;i++){
    if (answer.at(i)==1){
      cout<<i<<" ";
    }
  }
  cout<<endl;
  
  


}










