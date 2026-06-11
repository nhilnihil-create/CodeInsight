#include<bits/stdc++.h>

#define ll long long
const int inf = 1e9+7;
const ll INF = 1e18+7;

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin>>s;
  for(char &x : s){
    if(x == '?')
      x = 'D';
  }
  cout<<s<<"\n";
}
