#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,cou=0;
  cin>>N;
  string A;
  vector<string> item(N);
  for(int i=0;i<N;i++){
    cin>>A;
    item[i]=A;
  }
  cou=N;
  sort(item.begin(),item.end());
  for(int i=0;i<N-1;i++){
    if(item[i]==item[i+1]){
      cou--;
    }
  }
  cout<<cou<<endl;
}