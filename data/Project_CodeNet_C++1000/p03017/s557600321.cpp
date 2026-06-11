#include <iostream>
using namespace std;

bool checkForWalls(string s, int start, int end) {
  for(int i=start; i<end; i++){
    if(s[i] == '#' && s[i+1] == '#') return true;
  }
  return false;
}

bool checkEmpty(string s, int start, int end) {
  for(int i=start; i<=end; i++){
    if(s[i-1] == '.' && s[i] == '.' && s[i+1] == '.') return true;
  }
  return false;
}

int main(){
	int n, a, b, c , d;
	cin >> n >> a >> b >> c >> d; 
  a--; b--; c--; d--;
	string s; 
	cin >> s; 

  if(checkForWalls(s, a, c) || checkForWalls(s, b, d)) {
    cout << "No" << endl;
    return 0;
  }
	
  if (c < d){
    cout << "Yes" << endl;
    return 0;
  }

  cout << (checkEmpty(s, b, d) ? "Yes" : "No") << endl;
  return 0;
}

/* 
  First we check if :
  - there are two consecutive walls between A .. C. If there is, then "No"
  - there are two consecutive walls between B .. D. If there is, then "No"
  
  We check if :
  - C < D, then the answer is always possible
  - else :
      Find if there are three consecutive empty space between B .. D. If there is, then "Yes"
      else it's a "No"

*/