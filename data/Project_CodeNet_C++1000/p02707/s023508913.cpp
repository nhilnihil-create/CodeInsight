#include <bits/stdc++.h>
using namespace std;
using P=pair<int,int>;
int main(){
int N;
  cin>>N;
  vector<int>people(N,0);
  for(int i=0;i<N-1;i++){
  int a;
    cin>>a;
    people.at(a-1)++;
  }
  for(int i=0;i<N;i++){
  cout<<people.at(i)<<endl;
  }
}
  