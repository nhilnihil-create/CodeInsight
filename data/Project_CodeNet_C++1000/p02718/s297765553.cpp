#include <iostream>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, cnt = 0;
  double M;
  cin >> N >> M;
  double arr[N], sum = 0;
  for (int i = 0; i < N; i++){
    cin >> arr[i];
    sum += arr[i];
  }
  for (int i = 0; i < N; i++)
    if (arr[i] >= sum / (4 * M))
      cnt++;
  cout << ((cnt >= M)? "Yes" : "No") << '\n';
  return 0;
}
