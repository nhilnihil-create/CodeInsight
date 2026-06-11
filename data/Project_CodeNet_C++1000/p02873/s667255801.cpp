#include <bits/stdc++.h>
using namespace std;

#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)

#define ll long long

#define pq(name,type) priority_queue<type> name
#define vec(name,type,length,value) vector<type> name(length,value)
#define vec2(name,type,length,width,value) vector<vector<type>> name(length,vector<type>(width,value));

int main(){
	string N;
  cin >> N;
  ll ans = 0;
  int sl = N.length(),pre = 0;
 vector<int> a;
  vector<int> b;
  froop1(0,sl + 1){
    a.push_back(pre);
    if(i == sl)break;
    if(N[i] == '<'){
      pre += 1;
    }else{
      pre = 0;
    }
  }
    froop2(sl - 1,-2){
    b.push_back(pre);
      if(i == -1)break;
    if(N[i] == '>'){
      pre += 1;
    }else{
      pre = 0;
    }
  }
  froop1(0,sl + 1){
    ans += max(a.at(i),b.at(sl - i));
  }
  cout << ans << endl;

return 0;
}