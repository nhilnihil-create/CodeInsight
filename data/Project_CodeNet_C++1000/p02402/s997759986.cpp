#include <iostream>

using namespace std;

int main()
{
  int n;
  int a[10000];
  int max, min;
  long long sum;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    sum += a[i];
  }
  max = min = a[0];
  for(int i = 0; i < n; i++){
    if(min > a[i]) min = a[i];
    if(max < a[i]) max = a[i];
  }
  cout << min << " " << max << " " << sum << '\n';
    
}