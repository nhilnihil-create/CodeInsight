#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,M;
  cin >> N >> M;
  int H[N];
  int A[M],B[M];
  for(int i=0;i<N;i++) cin >> H[i];
  for(int i=0;i<M;i++){
    cin >> A[i] >> B[i];
  }
  vector<int> R[N+1];
  for(int i=0;i<M;i++){
    R[A[i]-1].push_back(B[i]);
    R[B[i]-1].push_back(A[i]);
  }
  int count = 0;
  for(int i=0;i<N;i++){
    int check=0;
    for(vector<int>::iterator j=R[i].begin();j!=R[i].end();j++){
      if(H[*j-1]>=H[i]){
        check=1;
      }
    }
    if(check==0) {
      count ++;
    }
  }
  cout << count;
}
