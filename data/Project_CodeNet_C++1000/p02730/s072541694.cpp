#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
string S,S1,S2;
cin>>S;
string Ans="Yes";
int N=S.size();
  for(int i=0;i<(N-1)/2;i++){S1+=S.at(i);}
  for(int i=(N+1)/2;i<N;i++){S2+=S.at(i);}
  
  for(int i=0;i<N;i++){if(S.at(i)!=S.at(N-1-i)){Ans="No";break;}}
  N=S1.size();
  for(int i=0;i<N;i++){if(S1.at(i)!=S1.at(N-1-i)){Ans="No";break;}}
  N=S2.size();
  for(int i=0;i<N;i++){if(S2.at(i)!=S2.at(N-1-i)){Ans="No";break;}}
  
  cout<<Ans<<endl;
}