#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int N;
  int count = 0;
  string str;
  
  cin >> N;
  cin >> str;
  
  for (int i = 0; i < N; i++)
    if (str.at(i) == 'A' && i < 48)
      if (str.at(i+1) == 'B')
        if (str.at(i+2) == 'C')
          count++;
  cout << count;
}