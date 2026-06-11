#include<iostream>

using namespace std;

int insertionsort(int* a,int n,int g,int cnt){
  for(int i = g; i < n; i++){
    int v = a[i];
    int j = i - g;
    while(j >= 0 && a[j] > v){
      a[j+g] = a[j];
      j -= g;
      cnt++;
    }
    a[j+g] = v;
  }
  return cnt;
}

int main(){
  int cnt = 0;
  int n;
  cin >> n;
  int a[n];
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  int x = n;
  int g[n];
  int m = 0;
  for(int i = 0; x > 1; i++){
    x = x - 1;
    g[i] = x;
    m++;
    x = x/3;
  }
  g[m] = 1;
  m++;
  for(int i = 0; i < m; i++){
    cnt = insertionsort(a,n,g[i],cnt);
  }
  cout << m << "\n";
  for(int i = 0; i < m; i++){
    if(i > 0){
      cout << " ";
    }
    cout << g[i];
  }
  cout << "\n";
  cout << cnt << "\n";

  for(int i = 0; i < n; i++){
    cout << a[i] << "\n";
  }

  return 0;
}

