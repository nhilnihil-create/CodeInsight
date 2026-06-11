#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int N,count=-1,figure=1;
  cin>>N;
  vector<int> a(N);
  for(int i=0; i<N; i++){
    cin>>a.at(i);
    if(a.at(i)==figure){
      count++;
      figure++;
    }
  }
  
  cout<<(count>=0?N-count-1:count)<<endl;
}
  