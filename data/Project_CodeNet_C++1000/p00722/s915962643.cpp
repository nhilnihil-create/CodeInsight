#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int a,d,n;
bool num[1000000 + 1];
vector<int> prime;
void serchPrime(){

  for(long i = 2; i < 1000000 ; i++){
    if(!num[i]){
      prime.push_back(i);
      for(long k = 1; i * k < 1000000 ; k++){
        num[i * k] = true;
      }
    }
  }
}

void solve(){

  int counta = 0;
  int primeCounta = 0;
  while(true){
    if(prime[primeCounta] < a){
      primeCounta++;
    }else if(prime[primeCounta] == a){
      counta ++;
      primeCounta++;
      break;
    }else{
      break;
    }
  }

  if(counta != n){
    for(int i = a; i < 1000000 ; ){
      i += d;
      while(true){
        // cout << "i = "<< i << endl;
        // cout << "Pcounta ="<<primeCounta << endl;
        if(prime[primeCounta] < i){
          primeCounta++;
        }else if(prime[primeCounta] == i){
          counta ++;
          primeCounta++;
          break;
        }else{
          break;
        }
      }
        if(counta == n) break;
    }
  }
  cout << prime[primeCounta - 1] << endl;

}

int main(){
  serchPrime();
  while(true){
    cin >> a >> d >> n;
    if(n == 0 && d == 0 && n == 0 )break;
    solve();
  }

  return 0;
}

