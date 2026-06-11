#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N,Ans=0;
  cin>>N;
  vector<int> vec(N);
  rep(i,N){cin>>vec.at(i);}
  sort(vec.begin(),vec.end());
  for (int i = 0; i < N-2; i++){
    for (int j = i+1; j < N-1; j++){
      for (int k = j+1; k < N; k++){if(vec.at(i)+vec.at(j)>vec.at(k)){Ans++;}
                                   }
    }
  }
  cout<<Ans<<endl;
}