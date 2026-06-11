#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main() 
{
  int N, K;
  cin >> N >> K;
  int h[N];
  for (int i = 0; i < N; i++){
    cin >> h[i];
  }

  int count = 0;
  for (int i = 0; i < N; i++){
    if (h[i] >= K){
      count++;
    }
  }

  cout << count << endl;
}
