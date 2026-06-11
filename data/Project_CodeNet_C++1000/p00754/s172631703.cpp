#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Rep(i, N) for(int i = 0; i < N; i++)

signed main()
{
  string S;
  bool izryt = false, flag = true;
  stack < char > st;
  
  while(getline(cin, S), izryt || S != ".") {
    izryt = true;
    Rep(i, S.size()) {
      if(S[i] == '.' && i == (int)S.size() - 1) {
	izryt = false;
      } else if(S[i] == '(' || S[i] == '[') {
	st.push(S[i]);
      } else if(S[i] == ')' || S[i] == ']') {
	if(!st.empty() && (S[i] == ')' && st.top() == '(' || S[i] == ']' && st.top() == '[')) {
	  st.pop();
	} else {
	  flag = false;
	}
      }
    }
    if(!izryt) {
      if(flag && st.empty()) cout << "yes" << endl;
      else cout << "no" << endl;

      while(!st.empty()) {
	st.pop();
      }
      flag = true;
    }
  }

  return 0;
}