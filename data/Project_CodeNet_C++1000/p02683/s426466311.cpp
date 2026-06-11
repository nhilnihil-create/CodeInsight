#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long N,M,X;
  cin >>N>>M>>X;
  
  long long min=-1;
  
  vector<vector<long long>> sina(20,vector<long long>(20));
  for(int i=0;i<N;i++){
    for(int a=0;a<M+1;a++){
      cin >> sina.at(i).at(a);
    }
  }
  for(long long ma=0;ma<(1 << N);ma++){
    bitset<20>ha(ma);
    vector<long long>total(20);
    bool judge=true;
    
    for(long long k=0;k<N;k++){
      if(ha.test(k)){
        for(long long a=0;a<M+1;a++)
        total.at(a)+=sina.at(k).at(a);
      }
    }
    for(long long p=1;p<M+1;p++){
      if(total.at(p)<X){
        judge=false;
      }
    }
    if(judge){
      if(min==-1){
        min=total.at(0);
      }
      else if(total.at(0)<min){
        min = total.at(0);
      }
    }
  }
  cout << min;
}
      
    
      
    
  