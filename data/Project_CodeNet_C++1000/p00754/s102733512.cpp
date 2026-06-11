#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>

#define REP(i,n) for(int i=0;i<n;++i)
#define REPR(i,n) for(int i=n;i>=0;--i)
#define REPI(itr,v) for(auto itr=v.begin();itr!=v.end();++itr)
#define REPIR(itr,v) for(auto itr=v.rbegin();itr!=v.rend();++itr)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define SORT(v,n) sort(v, v+n)
#define SORTV(v) sort(v.begin(), v.end())
#define ALL(v) v.begin(),v.end()
#define llong long long
#define INF 999999999
#define SUR 1000000007
#define pb push_back
#define pf push_front
#define MP make_pair

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

using namespace std;

typedef pair<int,int> pii;

int main(){

  while(true){
    string s;
    getline(cin, s);
    if(s == ".") break;

    int len = s.length();
    int l1 = 0, l2 = 0;
    bool f = true;
    stack<int> st; // (:1 [:2
    REP(i,len){
      if(s[i] == '('){
        l1++;
        st.push(1);
      }else if(s[i] == ')'){
        l1--;
        if(st.empty()){
          f = false;
          break;
        }
        int tmp = st.top(); st.pop();
        if(tmp == 2) f = false;
      }else if(s[i] == '['){
        l2++;
        st.push(2);
      }else if(s[i] == ']'){
        l2--;
        if(st.empty()){
          f = false;
          break;
        }
        int tmp = st.top(); st.pop();
        if(tmp == 1) f = false;
      }
    }
    if(f && l1 == 0 && l2 == 0){
      cout <<"yes\n";
    }else{
      cout <<"no\n";
    }
  }
  return 0;
}


