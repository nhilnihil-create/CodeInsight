#include <bits/stdc++.h>
#define P pair<int, int>

using namespace std;
const int INF=1e5;

int main(){
  long long n, a[100009];
  cin >> n;
  for(int i=0;i<n;i++)cin >> a[i];
  sort(a, a+n);
  long long ans=a[n-1]-a[0];
  for(int i=1;i<n-1;i++)ans+=abs(a[i]);
  cout << ans << endl;
  for(int i=1;i<n-1;i++){
    if(a[i]>=0){
      cout << a[0] << ' ' << a[i] << endl;
      a[0]-=a[i];
    }
    else{
      cout << a[n-1] << ' ' << a[i] << endl;
      a[n-1]-=a[i];
    }
  }
  cout << a[n-1] << ' ' << a[0] << endl;
}

