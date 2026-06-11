#include <bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i++)
#define ALL(a) (a).begin(),(a).end()
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define ll long long
#define ull unsigned long long
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

using namespace std;

int main(){
  while(true){
    vector<string> s;
    while(true){
      string tmp;
      getline(cin,tmp);
      s.push_back(tmp);
      if(tmp[tmp.size()-1] == '.')break;
    }
    //    REP(i,s.size())
    //    cout << s[i] <<endl;
    if(s.size()==1&&s[0][0]=='.')break;
    stack<int> st;
    bool is_theory = true;
    REP(i,s.size()){
      REP(j,s[i].size()){
	if(s[i][j] == '(')st.push(1);
	if(s[i][j] == '[')st.push(-1);
      if(s[i][j] == ')')
	if(!st.empty() && st.top() == 1)st.pop();
	else {is_theory = false;break;}
      if(s[i][j] == ']')
	if(!st.empty() && st.top() == -1)st.pop();
	else {is_theory = false;break;}
      }
    }
    if(is_theory && st.empty())cout << "yes" << endl;
    else cout << "no" << endl;
  }
	

  return 0;
}