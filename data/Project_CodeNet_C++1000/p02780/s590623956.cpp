#include <bits/stdc++.h>
using namespace std;

int main() {
  double N, K;
  cin >> N >> K;
  
  vector<double> p(N);
  for(int i=0; i<N ;i++){
    cin >> p.at(i);
  }
  
  double pnowa = 0;
    for(int j=0; j<K ; j++){
      pnowa = pnowa + p.at(j);
    }
  
  double saidai = pnowa;
  
  for(int i=0; i<N-K ; i++){
    pnowa = pnowa - p.at(i) + p.at(i+K);
        
    if(pnowa>saidai){
      saidai = pnowa;
    }
  }
  double kitaichi = (saidai+K)/2;
  
  
  printf("%.10f\n", kitaichi);
 
  
}

