#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int m = 3, G[100];
int l=0;
unsigned long long int cnt = 0;
void isort(int a[], int n, int g){
  for(int i = g; i < n; i++){
    int v = a[i];
    int j = i - g;
    while(j >= 0 && a[j] > v){
      a[j + g] = a[j];
      j -= g;
      cnt++;
    }
    a[j + g] = v;
  }
}
void shellsort(int a[], int n){
  l=0;
  for(int i = 1; i <= n; i = i * m +1)G[l++] = i;
  for (int i = l; i >=0; i--) isort( a, n, G[i]);
}
int main(){
  int n, a[1000000];
  cin>>n;
  for(int i = 0; i < n; i++) cin>>a[i];
  shellsort(a,n);
  printf("%d\n",l);
  for(int i = l-1; i > 0; i--)printf("%d ", G[i]);
  printf("%d\n", G[0]);
  printf("%llu\n", cnt);
  for(int i = 0; i < n; i++)printf("%d\n", a[i]);
  return 0;
}

