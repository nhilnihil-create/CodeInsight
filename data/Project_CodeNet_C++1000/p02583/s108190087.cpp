#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>

using namespace std;

void bubble(int L[], int n) {
  for(int i = 0; i < n; i++) {
    for(int j = n-1; j >= i+1; j--) {
      if(L[j] < L[j-1]) swap(L[j],L[j-1]);
    }
  }
}

int main() {
  int n,L[110];
  cin >> n;

  for(int i = 0; i < n; i++)
    cin >> L[i];

  bubble(L,n);

  int sum = 0;
  
  for(int i = 0; i < n; i++) {
    for(int j = i+1; j < n; j++) {
      for(int k = j+1; k < n; k++) {
        if(L[i] != L[j] & L[j] != L[k] & L[i]+L[j] > L[k])
          sum++;
      }
    }
  }
  cout << sum << endl;
}