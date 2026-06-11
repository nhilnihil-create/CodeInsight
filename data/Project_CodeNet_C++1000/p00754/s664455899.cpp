#include <bits/stdc++.h>

using namespace std;

int main()
{
  string s;
  while(getline(cin, s), s != "."){
    stack<int> bkt;
    for(int i = 0; i < s.size(); i++){
      if(s[i] == '(') bkt.push(1);
      else if(s[i] == '[') bkt.push(2);
      else if(s[i] == ')'){
	if(bkt.empty() || bkt.top() == 2){
	  bkt.push(-1);
	  break;
	} else {
	  bkt.pop();
	}
      }
      else if(s[i] == ']'){
	if(bkt.empty() || bkt.top() == 1){
	  bkt.push(-1);
	  break;
	} else {
	  bkt.pop();
	}
      }
    }
    if(bkt.empty()) cout << "yes" << endl;
    else cout << "no" << endl;
    cin.clear();
  }
  return 0;
}