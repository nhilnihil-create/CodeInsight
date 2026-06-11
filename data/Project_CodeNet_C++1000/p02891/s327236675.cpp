#include <iostream>
#include <vector>
using namespace std;

bool allLettersSame(string s){
  for(int i=0; i<s.size(); i++){
    if(s[i] != s[0]) return false;
  }
  return true;
}

int main() {
  string s;
  cin >> s;

  long long k;
  cin >> k;

  if(allLettersSame(s)){
    cout << k * s.size() / 2;
    return 0;
  }

  long long ans = 0;
  int kiri = 0, kanan = 0;

  vector<int> counter;
  while(kiri < s.size()){
    while(kanan + 1 < s.size() && s[kiri] == s[kanan+1])
      kanan++;
    ans += (kanan - kiri + 1)/2;
    counter.push_back(kanan-kiri+1);
    kiri = kanan+1;
    kanan = kiri;
  }
  ans *= k;

  if(s[0] == s[s.size()-1] && counter[0]%2 == 1 && counter.back()%2==1){
    ans += k-1;
  }

  cout << ans << endl;
}