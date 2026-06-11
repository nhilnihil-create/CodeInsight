#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

int main(){
  int N,Q;
  ll K;
  cin >> N >> K >> Q;
  int A[Q];
  ll B[N];
  for(int i=0;i<N;i++){
    B[i]=K;
  }
  for(int i=0;i<Q;i++){
    cin >> A[i];
    ++B[A[i]-1];
  }
  for(int i=0;i<N;i++){
    B[i]-=Q;
    if(B[i]>0){
      cout << "Yes" <<endl;
    }else cout << "No" <<endl;
  }
}

