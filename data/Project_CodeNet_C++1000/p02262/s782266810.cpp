#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

long long int cnt = 0;
vector<int> a;
vector<int> g;

void insertionSort(int n, int x){
  for(int i = x; i < n; i++){
    int v = a[i];
    int j = i - x;

    while(j >= 0 && a[j] > v){
      a[j+x] = a[j];
      j -= x;
      cnt++;
    }
    
      a[j+x] = v;    
  }
}

void shellSort(int n){
  
  for(int i = 1; i <= n; i = 3*i + 1){
    g.push_back(i);
  }

  for(int i = g.size() - 1; i >= 0; i--){
    insertionSort(n, g[i]);
  }
}

int main()
{
  int n;
  
  scanf("%d", &n);
  a.resize(n);

  for(int i = 0; i < n; i++) scanf("%d", &a[i]);

  shellSort(n);

  cout << g.size() << endl;

  for(int i = g.size() - 1; i >= 0; i--){
    printf("%d", g[i]);
    if(i) printf(" ");
    
  }

  printf("\n");

  printf("%lld\n", cnt);

  for(int i = 0; i < n; i++) printf("%d\n", a[i]);

  return 0;

}

