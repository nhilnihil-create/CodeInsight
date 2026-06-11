#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int n, sum = 0;
  cin >> n;
  vector < int > a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
    sum += a[i];
  }
  sort(a.begin(), a.end());

  if(a[0] >= 0){
    cout << sum - 2 * a[0] << '\n';
    for(int i = 1; i < n - 1; i++){
      cout << a[0] << " " << a[i] << '\n';
      a[0] -= a[i];
    }
    cout << a[n - 1] << " " << a[0] << '\n';
  }else if(a[n - 1] < 0){
    cout << 2 * a[n - 1] - sum << '\n';
    for(int i = 0; i < n - 1; i++){
      cout << a[n - 1] << " " << a[i] << '\n';
      a[n - 1] -= a[i];
    }
  }else{
    int j = 0;
    for(int i = 0; i < n; i++){
      if(a[i] >= 0){
        j = i;
        break;
      }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) ans += abs(a[i]);
    cout << ans << '\n';
    for(int i = j; i < n - 1; i++){
      cout << a[0] << " " << a[i] << '\n';
      a[0] -= a[i];
    }
    for(int i = 0; i < j; i++){
      cout << a[n - 1] << " " << a[i] << '\n';
      a[n - 1] -= a[i];
    }
  }
}
