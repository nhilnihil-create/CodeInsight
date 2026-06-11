#include<queue>
#include<stack>
#include<math.h>
#include<cmath>
#include<bitset>
#include<stdio.h>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<utility>
#include<functional>
#include<deque>
#include<list>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int main(){
  ll i;
  vector<vector<ll> > x(30);
  string s,t;
  cin >> s >> t;
  for(i=0;i<s.size();i++){
    x[s[i]-'a'].push_back(i);
  }
  for(i=0;i<t.size();i++){
    if(x[t[i]-'a'].size()==0){
      printf("-1\n");
      return 0;
    }
  }
  ll b=0,c=0;
  for(i=0;i<t.size();i++){
    ll mid,min=-1,max=x[t[i]-'a'].size();
    while(abs(min-max)>1){
      mid=(min+max)/2;
      if(x[t[i]-'a'][mid]>=c){
        max=mid;
      }
      else{
        min=mid;
      }
    }
    if(max==x[t[i]-'a'].size()){
      b++,c=0;
      i--;
    }
    else{
      c=x[t[i]-'a'][max]+1;
    }
  }
  cout << b*s.size()+c << endl;
}