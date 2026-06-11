#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;
int main(){
  long long kazu;
  cin >> kazu;
  vector<int> nagasa(kazu);
  long long goukei = 0;
  for(int i = 0;i <= kazu - 1;i++){
    cin >> nagasa[i];
    goukei += nagasa[i];
  }
  vector<long long> kei(kazu);
  kei[0] = nagasa[0];
  for(int i = 1;i <= kazu - 1;i++){
    kei[i] = kei[i - 1] + nagasa[i];
  }
  long long saisyou = 0;
  saisyou = -1;
  for(int i = 0;i <= kazu - 1;i++){
    if(abs((goukei - kei[i]) - kei[i]) <= saisyou || saisyou == -1){
      saisyou = abs((goukei - kei[i]) - kei[i]);
    }
  }
  cout << saisyou << endl;
}