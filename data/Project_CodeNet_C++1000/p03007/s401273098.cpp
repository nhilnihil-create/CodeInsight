#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;
#define MAX 1000000
#define MOD 1000000007
#define INF 100000000000000


int main(){
  int N;
  cin>>N;
  vector<ll> A(N);
  bool plus=false;
  bool minus=false;
  bool zero=false;
  ll sum=0;
  for(int i=0;i<N;i++){
    cin>>A.at(i);
    sum+=abs<ll>(A.at(i));
    if(A.at(i)>0){
      plus=true;
    }else if(A.at(i)<0){
      minus=true;
    }else{
      zero=true;
    }
  }
  sort(A.begin(),A.end());
  if((plus&&minus)||zero){
    int k=lower_bound(A.begin(),A.end(),0)-A.begin();
    cout<<sum<<endl;
    for(int i=k;i<N-1;i++){
      if(i==0){
        continue;
      }
      cout<<A.at(0)<<" "<<A.at(i)<<endl;
      A.at(0)-=A.at(i);
    }
    for(int i=0;i<k;i++){
      cout<<A.at(N-1)<<" "<<A.at(i)<<endl;
      A.at(N-1)-=A.at(i);
    }
    if(k==0){
      cout<<A.at(N-1)<<" "<<A.at(0)<<endl;
    }
  }else if(plus){
    cout<<sum-2*A.at(0)<<endl;
    for(int i=1;i<N-1;i++){
      cout<<A.at(0)<<" "<<A.at(i)<<endl;
      A.at(0)-=A.at(i);
    }
    cout<<A.at(N-1)<<" "<<A.at(0)<<endl;
  }else{
    cout<<sum+2*A.at(N-1)<<endl;
    for(int i=0;i<N-1;i++){
      cout<<A.at(N-1)<<" "<<A.at(i)<<endl;
      A.at(N-1)-=A.at(i);
    }
  }
}
