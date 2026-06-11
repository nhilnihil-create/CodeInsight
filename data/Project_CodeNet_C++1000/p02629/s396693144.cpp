#include <bits/stdc++.h>
using namespace std;

int main(){
  long long int N, num = 0;
  char conv[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  cin >> N;
  
  vector<int> alp(0);
  
  while (N > 0){
    num = N % 26;
    if (num == 0){
      num = 26;
    }
    alp.push_back(num);
    
    N -= num;
    N /= 26;
  }
  
  string ans = "";
  
  for (int i = alp.size() - 1; i >= 0; i--){
    ans += conv[alp.at(i) - 1];
  }
  
  cout << ans << endl;
}