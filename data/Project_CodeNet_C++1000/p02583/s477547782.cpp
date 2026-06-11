#include <iostream>

using namespace std;

int main(){
  int N;
  cin >> N;
  int L[N];
  int tri[3];
  int cnt(0);
  for (int i = 0; i < N; ++i)
  {
    cin >> L[i];
  }
  
  for (int i = 0; i + 2 < N; ++i)
  {
    for (int j = i+1; j + 1< N; ++j)
    {
      for (int k = j+1; k < N; ++k)
      {
        tri[0] = max(max(L[i], L[j]), L[k]);
        tri[1] = min(min(L[i], L[j]), L[k]);
        tri[2] = L[i] + L[j] + L[k] - tri[0] - tri[1];
        if ( L[i] < L[j] + L[k] && L[j] < L[i] + L[k] && L[k] < L[j] + L[i] && L[i] != L[j] && L[i] != L[k] && L[k] != L[j])
          cnt++;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}