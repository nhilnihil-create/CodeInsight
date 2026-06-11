#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,a,num=1,count=0;
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>a;
    if(a==num){
      count++;
      num++;
    }
  }
  if(count>0)cout<<N-count<<endl;
  else cout<<"-1"<<endl;
}
