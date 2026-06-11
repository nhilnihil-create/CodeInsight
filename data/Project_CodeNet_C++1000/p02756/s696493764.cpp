#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef tuple<int,int,int> tii;
#define rep(i,s,n) for(int i=(int)(s);i<(int)(n);i++)

int main(){
  string s; int q;
  cin >> s >> q;
  deque<char> deq;
  for(int i=0;i<s.size();i++){
    deq.push_back(s[i]);
  }
  int f = 0;
  for(int i=0;i<q;i++){
    int x; cin >> x;
    if(x==1){
      f++;
      continue;
    }
    int ff; char c;
    cin >> ff >> c;
    if((ff+f)%2==0) deq.push_back(c);
    else deq.push_front(c);
  }
  string ans = "";
  if(f%2==1){
    while(!deq.empty()){
      ans += deq.back();
      deq.pop_back();
    }
  }else{
    while(!deq.empty()){
      ans += deq.front();
      deq.pop_front();
    }
  }
  cout << ans << endl;
  
}