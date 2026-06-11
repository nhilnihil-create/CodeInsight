# include <iostream>
# include <vector>
using namespace std;

bool allLettersSame(string s){
  for(int i=0; i<s.size(); i++){
    if(s[i] != s[0]) return false;
  }
  return true;
}

int main(){
  string s;
  cin >> s;
  
  long long k;
  cin >> k;
  
  if(allLettersSame(s)){
    cout << s.size()*k / 2 << endl;
    return 0;
  }
  
  int left=0, right=0;
  long long ans = 0;
  
  vector<int> counters;
  while(left < s.size()){
    while(right+1 < s.size() && s[left] == s[right+1])
      right++;
    
    int cnt = right - left + 1;
    counters.push_back(cnt);
    ans += cnt/2;
    left = right+1;
    right = left;
  }
  
  ans *= k;
  
  if(s[0] == s[s.size()-1] && 
    counters[0]%2==1 && 
    counters.back()%2==1 && 
    counters.size() != 1)
    ans += k-1;
  
  cout << ans << endl;
  return 0;
}