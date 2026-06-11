#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000

int main(){
  string S; cin >> S;
  stack<string> st;

  for (int i=0;i<S.size();i++){
    if (st.empty() || st.top().size()==2 || S.substr(i,1)!=st.top()) { //1文字追加
      st.push(S.substr(i,1));
    }
    else if (i<S.size()-1 ){ 
      st.push(S.substr(i,2));
      i++;
    }
    else {
      st.pop();
      st.push(S.substr(i-1,2));
    }
    
  }

  cout << st.size() << endl;

  return 0;
}