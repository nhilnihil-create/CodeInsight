#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string str;
  cin >> N >> str;
  int i=0;
  int j=N-1;
  int count=0;
  while(i<j){
    while(str.at(i)=='R' && i < N-1){
      i++;
    }
    while(str.at(j)=='W' && j > 0){
      j--;
    }
    if(i<j){
      count++;
      i++;
      j--;
    }
  }
  cout << count << endl;
}
