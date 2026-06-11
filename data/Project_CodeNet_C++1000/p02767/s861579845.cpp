#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int inf = 1000000000; // 10^9

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int N;
  cin >> N;
  int arr[N];
  int res = inf;

  // Store X-coordinates. 
  for(int i=0; i<N; i++) {
    cin >> arr[i];
  }

 
  // Brute force for all possible coordinates.
  for(int i=1; i<=100; i++) {
    int cost = 0;
    // Calculate cost (stamina) for meeting a point i.
    for(int j=0; j<N; j++) {
      cost += (arr[j] - i) * (arr[j] - i);
    }
    // Compare the cost to the previous min. cost.
    res = min(res,cost);
  }
  
  cout << res << '\n';
  return 0;
}

