#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,count;
  count=0;
  cin>>N;
  vector<string>vec(N);
  vector<int>time(N);
  for(int i=0;i<N;i++){
    string s;
    int a;
    cin>>s>>a;
    vec.at(i)=s;
    time.at(i)=a;
  }
  string last;
  cin>>last;
  for(int i=0;i<N-1;i++){
    if(vec.at(i)==last){
      for(int j=i+1;j<N;j++){
        count+=time.at(j);
      }
    }
  }
  cout<<count<<endl;
  
      
}
