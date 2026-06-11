//vinay
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9+7;
#define flash ios_base::sync_with_stdio(false);cin.tie(0);
// C++ program to print all 
// permutations with duplicates allowed 
typedef pair<int, int > pii;
const int INF = 1e9+5;

int main(){
  string s;
  cin >> s;
  ll x = 0, f = 0;
  for(ll i = 0; i < s.size(); i++){
      x += s[i]-'0';
  } 
  if(x%9 == 0){
      cout << "Yes" << endl;
    }
    else
      cout << "No"<< endl;
}