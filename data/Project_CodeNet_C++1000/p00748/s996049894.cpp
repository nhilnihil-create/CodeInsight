#include<iostream>
#include<vector>
#include<utility>
using namespace std;
int main(int argc, char *argv[])
{
  const int N = 1000001;
  vector<int> full(N);
  vector<int> odd(N);
  for(int i = 0; i < N; i++) full[i] = i;
  for(int i = 0; i < N; i++) odd[i] = i;
  for(int n = 2; ; n++) {
    const int t = (n * (n+1) * (n+2))/6;
    if(t >= N) break;
    for(int i = 0; i + t < N; i++) {
      const int k = i + t;
      if(full[i] + 1 < full[k]) full[k] = full[i] + 1;
      if(t & 1) {
        if(odd[i] + 1 < odd[k]) odd[k] = odd[i] + 1;
      }
    }
  }
  
  for(int t = 1;; t++) {
    int n;
    cin >> n;
    if(n == 0) break;
    cout << full[n] << " " << odd[n] << endl;
  }
  return 0;
}