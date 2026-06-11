#include <bits/stdc++.h>
using namespace std;

int main() {
  string N;
  cin >> N;
  for(char&x:N){
   if(x=='?')x='D'; 
  }
  cout << N << endl;
}