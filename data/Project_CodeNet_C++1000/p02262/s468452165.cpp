// -*- coding:utf-8 -*-
#include<iostream>


void print_list(int* a, int n){
  for(int i = 0; i < n - 1; i++){
    std::cout << a[i] << " ";
  }
  std::cout << a[n - 1] << std::endl;
}

int cnt = 0;
void insertionSort(int* a, int n, int g){
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

void shellSort(int* a, int n){
  int m = 13;
  int g[] = {797161, 265720, 88573, 29524, 9841,
  	     3280, 1093, 364, 121, 40, 13, 4, 1, };
  int t;
  for(int i = 0; i < m; i++){
    if(g[i] <= n){
      t = i;
      break;
    }
  }
  for(int i = t; i < m; i++){
    insertionSort(a, n, g[i]);
  }

  std::cout << (m - t) << std::endl;
  for(int i = t; i < m - 1; i++){
    std::cout << g[i] << " ";
  }
  std::cout << g[m - 1] << std::endl;
  
  std::cout << cnt << std::endl;
  for(int i = 0; i < n; i++){
    std::cout << a[i] << std::endl;
  }
}

int main(){
  int n;
  std::cin >> n;

  int a[n];
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }
  
  shellSort(a, n);
 
  return 0;
}

