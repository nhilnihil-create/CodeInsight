#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N,X,Y;
  cin>>N>>X>>Y;
  X--,Y--;
  map<int,int> A;
  for(int i=0;i<N-1;i++)
    for(int j=i+1;j<N;j++){
      int k;
      if(i<=X && Y<=j)
        k=j-i-(Y-X)+1;
      else if(X<=i && j<=Y)
        k=min(j-i,Y-X+1-(j-i));
      else if(j<=X || Y<=i)
        k=j-i;
      else if(i<=X && j<=Y)
        k=X-i+min(j-X,Y-j+1);
      else if(X<=i && Y<=j)
        k=j-Y+min(Y-i,i-X+1);
      A[k]++;
    }
  for(int i=1;i<N;i++)
    cout<<A[i]<<endl;
}