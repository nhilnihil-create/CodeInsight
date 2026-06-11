#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;cin>>N;long long K=0;
  vector<vector<int>> V(10,vector<int>(10));
  for(int X=1;X<=N;X++){
    string S=to_string(X);
    V[((int)S[0])-48][((int)S[S.size()-1])-48]++;
  }
  for(int X=1;X<10;X++){
    for(int Y=1;Y<10;Y++){
      K+=V[X][Y]*V[Y][X];
    }
  }
  cout<<K<<endl;
}