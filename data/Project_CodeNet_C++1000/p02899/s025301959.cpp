#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
 cin>>N;
  vector<pair<int,int>> A(N);
   for(int i=0;i<N;i++){
    int a;
    cin>>a;
     A.at(i)=make_pair(a,i);
   }
  sort(A.begin(),A.end());
  
  for(int i=0;i<N;i++){
    int a;
    tie(ignore,a)=A.at(i);
    cout<<a+1<<" ";
  }
  cout<<endl;
}