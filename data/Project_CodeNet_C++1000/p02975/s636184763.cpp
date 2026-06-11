#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007
#define INF 1000000000000000000

int main(){
  int N;
  cin>>N;
  vector<int> a(N);
  bool zero=true;
  for(int i=0;i<N;i++){
    cin>>a.at(i);
    if(a.at(i)!=0){
      zero=false;
    }
  }
  if(zero){
    cout<<"Yes"<<endl;
  }else if(N%3!=0){
    cout<<"No"<<endl;
  }else{
    bool flag=true;
    for(int i=0;i<32;i++){
      int counter=0;
      for(int j=0;j<N;j++){
        counter+=a.at(j)%2;
        a.at(j)/=2;
      }
      if(counter!=0&&counter!=(2*N/3)){
        flag=false;
        break;
      }
    }
    if(flag){
      cout<<"Yes"<<endl;
    }else{
      cout<<"No"<<endl;
    }
  }
}
