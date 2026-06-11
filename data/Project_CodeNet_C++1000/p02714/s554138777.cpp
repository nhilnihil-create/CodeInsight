#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N;
  string S;
  cin>>N>>S;
  int k=0;
  for(int i=1;i<=(N-1)/2;i++)
    for(int j=0;j+i*2<N;j++)
      if(S[j]!=S[j+i] && S[j]!=S[j+i*2] && S[j+i]!=S[j+i*2])
        k++;
  map<int,int> A;
  for(char c:S)
    A[c]++;
  cout<<A['R']*A['G']*A['B']-k<<endl;
}