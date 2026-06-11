#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N,L;
  cin>>N>>L;
  
  
  if(L+N-1<=0){
    int sum_1=(L-1)*(N-1);
    for(int i=1;i<N;i++){
      sum_1+=i;
    }
    cout<<sum_1<<endl;
  }
  
  else if(L<=0&&L+N-1>=0){
    int sum_2=(L-1)*N;
    for(int i=1;i<=N;i++){
      sum_2+=i;
    }
    cout<<sum_2<<endl;
  }
  else{
    int sum_3=(L-1)*(N-1);
    for(int i=2;i<=N;i++){
      sum_3+=i;
    }
    cout<<sum_3<<endl;
  }
}