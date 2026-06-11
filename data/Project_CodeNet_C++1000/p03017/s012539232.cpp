# include <iostream>
using namespace std;

bool checkPager(string s, int start, int finish){
  for(int i=start+1; i<=finish; i++){
    if(s[i] == '#' && s[i-1] == '#') return true; 
  }
  return false;
}

bool checkTitik(string s, int start, int finish){
  for(int i=start; i<=finish; i++){
    if(s[i-1] == '.' && s[i] == '.' && s[i+1] == '.')
      return true;
  }
  return false;
}

int main(){
  int n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  a--; b--; c--; d--;
  string s;
  cin >> s;
  
  if(checkPager(s, a, c) || checkPager(s, b, d)){
    cout << "No" << endl;
    return 0;
  }
  
  if (c < d){
    cout << "Yes" << endl;
    return 0;
  }
  
  if(checkTitik(s, b, d)){
    cout << "Yes" << endl;
  }
  else cout << "No" << endl;
  return 0;
}