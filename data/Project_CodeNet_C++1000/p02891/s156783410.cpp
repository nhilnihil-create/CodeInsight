#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  int64_t Nrep;
  cin >> S >> Nrep;

  const int64_t Nlen= (int64_t) S.size();
  const int64_t Ninter= Nrep- 1;

  vector<int64_t> piece;
  int64_t Nop_intra= 0;
  int64_t right= 0;
  for(int64_t left=0; left<Nlen;){
    while(right+ 1 < Nlen && S.at(left)==S.at(right+1)){
      right++;
    }

    int64_t Lpiece= right+1 -left;
    piece.emplace_back(Lpiece);
    Nop_intra+= Lpiece/ 2;

    left= right+1;
  }

  int64_t Nop_inter= 0;
  if(S.at(0)==S.back()){
    Nop_intra-= (piece.at(0)/2)+ (piece.back()/2);
    Nop_inter= (piece.at(0)+ piece.back())/ 2;
  }

  int64_t ans= (piece.size()==1)     ? Nlen* Nrep/ 2
              :(S.at(0) != S.back()) ? Nop_intra* Nrep
                                     : Nop_intra* Nrep+ Nop_inter*(Nrep-1)+ (piece.at(0)/2)+ (piece.back()/2);


  cout << ans << endl;
}