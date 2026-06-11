#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N;
  cin>>N;
  vector<int> A(N);
  int a=0,b=0;
  for(int &i:A){
    cin>>i;
    if(i>0)a++;
    else b++;
  }
  sort(A.begin(),A.end());
  vector<pair<int,int>> B;
  if(a==N){
    for(int i=2;i<N;i++){
      B.push_back({A[0],A[i]});
      A[0]-=A[i];
    }
    B.push_back({A[1],A[0]});
    A[1]-=A[0];
    cout<<A[1]<<endl;
    for(pair<int,int> p:B)cout<<p.first<<' '<<p.second<<endl;
    return 0;
  }
  if(b==N){
    for(int i=0;i<N-1;i++){
      B.push_back({A[N-1],A[i]});
      A[N-1]-=A[i];
    }
    cout<<A[N-1]<<endl;
    for(pair<int,int> p:B)cout<<p.first<<' '<<p.second<<endl;
    return 0;
  }
  for(int i=1;i<a;i++){
    B.push_back({A[b-1],A[N-i]});
    A[b-1]-=A[N-i];
  }
  for(int i=0;i<b;i++){
    B.push_back({A[b],A[i]});
    A[b]-=A[i];
  }
  cout<<A[b]<<endl;
  for(pair<int,int> p:B)cout<<p.first<<' '<<p.second<<endl;
}