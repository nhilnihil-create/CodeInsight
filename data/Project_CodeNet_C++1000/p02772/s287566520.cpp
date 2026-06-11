#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<int> vec(N);
  for(int i=0;i<N;i++){
  cin>>vec.at(i);
  }
  int count=0;
  for(int i=0;i<N;i++){
    if(vec.at(i)%2==0){
      if(vec.at(i)%3!=0&&vec.at(i)%5!=0)
        count++;
    }
  }
  if(count>0) cout<<"DENIED"<<endl;
  else cout<<"APPROVED"<<endl;
}
  