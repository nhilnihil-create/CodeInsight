#include<iostream>
using namespace std;

int main() {
  
  int gyo,retu;
  int sum[100] = {0};
  int vec1[100][100];
  int vec2[100];
  
  cin >> retu >> gyo;
  
  for (int i = 0; i < retu; i++) {
    for (int j = 0; j < gyo; j++) {
      cin >> vec1[i][j];
    }
  }
  
  for (int i = 0; i < gyo; i++) {
    cin >> vec2[i];
  }
  
  for (int i = 0; i < retu; i++) {
    for (int j = 0; j < gyo; j++) {
      sum[i] += vec1[i][j] * vec2[j];
    }
    cout << sum[i] <<endl;
  }
  
}