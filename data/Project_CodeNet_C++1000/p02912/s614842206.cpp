#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 1e9;

int main(){
  int n,m;
  cin >> n >> m;
  const int max_n = 1e5;
  // vector<int> a(n);
  priority_queue<int> a;
  for(int i = 0; i < n; i++) {
    int in;
    cin >> in;
    a.push(in);
  }

  // sort(a.begin(), a.end());
  
  for(int i = 0; i < m; i++){
    // int left = 0;
    // int right = n-1;
    // int price = a[n-1] / 2;
    // while(right - left > 1){
    //   int x = (right + left) / 2;
    //   if(a[x] > price) right = x;
    //   else left = x;
    // }
    // a.insert(a.begin() + right, price);
    // // for(int i = 0; i < n; i++) cout << a[i] << ", ";
    // // cout << endl;

    int price = a.top() / 2;
    a.pop();
    a.push(price);
  }
  long long sum = 0;
  // for(int i = 0; i < n; i++) sum += a[i];
  for(int i = 0; i < n; i++){
    sum += a.top();
    a.pop();
  }
  cout << sum << endl;

  return 0;
}