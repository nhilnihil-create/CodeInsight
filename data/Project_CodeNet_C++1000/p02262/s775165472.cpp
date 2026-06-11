#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int N,A[1000001];
vector<int> G;
int cnt;
int insert(int *A,int N,int g){
  for(int i=g;i<N;i++){
    int v=A[i];
    int j=i-g;
    while(j>=0 && A[j]>v){
      A[j+g]=A[j];
      j-=g;
      cnt++;
    }
    A[j+g]=v;
  }
}
int shell(int *A,int N){
  int h=1;
  while(h<=N){
    G.push_back(h);
    h=3*h+1;
  }
  for(int i=G.size()-1;i>=0;i--)insert(A,N,G[i]);
}
int main(){
  
  cin >> N;
  for(int i=0;i<N;i++)cin >> A[i];
  
  shell(A,N);

  cout << G.size() << endl;
  for(int i=G.size()-1;i>=0;i--){
    cout << G[i];
    if(i)cout << " " ;
  }
  cout << endl;
  cout << cnt << endl;
  for(int i=0;i<N;i++)cout << A[i] << endl;
  return 0;
}