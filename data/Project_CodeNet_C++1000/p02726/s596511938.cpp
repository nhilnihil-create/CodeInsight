#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N,X,Y;
  cin>>N>>X>>Y;
  X--,Y--;
  vector<int> A(N);
  for(int i=0;i<N;i++)
    for(int j=i+1;j<N;j++){
      A[min(abs(X-i)+abs(Y-j)+1,j-i)]++;
    }
  for(int i=1;i<N;i++)cout<<A[i]<<endl;
}