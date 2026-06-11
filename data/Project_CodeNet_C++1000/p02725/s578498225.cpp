#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int K, M;
  cin >> K >> M;
  int arr[M], temp, maximum = 0;
  for (int i = 0; i < M; i++){
    cin >> temp;
    arr[i] = ((temp > K / 2)? temp - K : temp);
  }
  sort(arr, arr + M);
  for (int i = 1; i < M; i++)
    if (arr[i] - arr[i - 1] > maximum)
      maximum = arr[i] - arr[i - 1];
  cout << min(K - maximum, arr[M - 1] - arr[0]);
  return 0;
}
