#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define INT(str) stoi((str), 0)
#define INTB(str) stoi((str), 0, 2)
 
int main() {
  vi ABC(3);
  REP(i,3) cin >> ABC.at(i);
  sort(ABC.begin(), ABC.end());
  if(ABC.at(0) == ABC.at(2))
    cout << "No" << endl;
  else if (ABC.at(1) == ABC.at(0) || ABC.at(1) == ABC.at(2))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;    
}