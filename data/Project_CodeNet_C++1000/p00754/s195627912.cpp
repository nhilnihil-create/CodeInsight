#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(a) max((a),-(a))
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repe(i,n) rep(i,(n)+1)
#define per(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pere(i,n) rep(i,(n)+1)
#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define RET return 0
#define MOD 1000000007
#define INF 1000000000000000000

typedef long long LL;
typedef long double LD;

int main(){
  string s;
  while(getline(cin,s)){
    if(s==".") return 0;
    stack<int> ss;
    for(int i=0;i<s.length();i++){
      if(s[i]=='('){
        ss.push(0);
      }else if(s[i]=='['){
        ss.push(1);
      }else if(s[i]==')'){
        if(ss.empty()){
          cout << "no" << endl;
          goto next;
        }
        if(ss.top()==0){
          ss.pop();
        }else{
          cout << "no" << endl;
          goto next;
        }
      }else if(s[i]==']'){
        if(ss.empty()){
          cout << "no" << endl;
          goto next;
        }
        if(ss.top()==1){
          ss.pop();
        }else{
          cout << "no" << endl;
          goto next;
        }
      }
    }
    if(ss.empty()){
      cout << "yes" << endl;
    }else{
      cout << "no" << endl;
    }
    next:
    continue;
  }
  return 0;
}

