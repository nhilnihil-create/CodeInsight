#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,cnt = 0,a[110];
  cin >> n;
  for(int i = 0; i < n; i++){
        cin >> a[i];
  }
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
        for(int k = j+1; k < n; k++){
            if(a[i]!=a[j] && a[i]!=a[k] && a[j]!=a[k]){
                if(a[i]+a[j] > a[k] && abs(a[i] - a[j]) < a[k])
                    cnt++;
                }
            }
        }
    }
    cout << cnt << endl;
  return 0;
}
