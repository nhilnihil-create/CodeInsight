 #include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

#define ll long long

int main(){
  ll n;
  cin >> n;
  unordered_set<string> us;
  for(ll i = 0; i < n; i++){
    string a,b;
    cin >> a >> b;
    if(a == "insert"){
      us.insert(b);
    }else{
      if(us.find(b) == us.end()){
	cout << "no\n";
      }else{
	cout << "yes\n";
      }
    }
  }
}