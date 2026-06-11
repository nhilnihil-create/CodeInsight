#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 1e9;

int main(){
  string s;
  cin >> s;
  const int max_size = 1e5;
  int a[max_size+1];
  int size = s.length();

  for(int i = 0; i < size; i++){
    a[i] = 0;
  }

  bool flag = 0;
  int now = 0;
  for(int i = 1; i < size; i++){
    if(s[i] == 'L' && flag == 0){
      flag = 1;
      for(int j = now; j < i; j++){
        if((i-j)%2 == 1) a[i-1] += 1;
        else a[i] += 1;
      }
      if(i == size - 1){
        a[size-1] ++;
      }
      now = i;
    }else if((s[i] == 'R' && flag == 1) || i == size - 1){
      flag = 0;
      for(int j = now; j < i; j++){
        if((j - now)%2 == 0) a[now] += 1;
        else a[now-1] += 1;
        if(j+1 == size - 1){
          if((size-1 - now)%2 == 0) a[now] += 1;
          else a[now-1] += 1;
        }
      }
      now = i;
    }
  }
  for(int i = 0; i < size; i++){
    if(i != size - 1) cout << a[i] << " ";
    else cout << a[i] << endl;
  }

  return 0;
}