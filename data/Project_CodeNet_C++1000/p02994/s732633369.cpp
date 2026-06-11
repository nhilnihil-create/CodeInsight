#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,L;
  cin >> N >> L;
  
  int a=(2*L+N-1)*N/2;
  if(L<=0 && L+N-1 >=0){
    cout << a <<endl;
  }
  if(L>0){
    cout << a-L <<endl;
  }
  if(L+N-1<0){
    cout << a-L-N+1 <<endl;
  }
}

      