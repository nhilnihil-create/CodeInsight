#include <iostream>

using namespace std;

int const NMAX = 1e5;
int freq[1 + NMAX];

int main() {

  long long n, m, k = 1000000000000000001, p;
  cin >> n >> m >> k;
  //n = n % m;
  for(int i = 1;i <= k;i++){
    cin >> p;
    freq[p]++;
  }
  for(int i =1;i <= n;i++){
    if(m + freq[i] - k > 0){
      cout << "Yes\n";
    }else{
      cout << "No\n";
    }
  }
  return 0;
}
