#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  map<string,string> m;
  m["Sunny"] = "Cloudy";
  m["Cloudy"] = "Rainy";
  m["Rainy"] = "Sunny";

  string S; cin >> S;
  cout << m[S] << endl;
}
