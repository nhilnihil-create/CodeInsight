#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<pair<int,int>> A(N);
  for(int i=0;i<N;i++){
    int X,L;
    cin>>X>>L;
    A[i]=make_pair(X+L,X-L);
  }
  sort(A.begin(),A.end());
  int k=0,r=0;
  for(int i=0;i<N;i++){
    r=A[i].first;
    k++;
    for(i++;i<N;i++)
      if(A[i].second>=r){
        i--;
        break;
      }
  }
  cout<<k<<endl;
}