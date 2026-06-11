#include<bits/stdc++.h>
#define Vsort(a) sort(a.begin(), a.end())
#define rep(i,n) for(int i = 0; i < (n); i++)
#define Srep(i,a,n) for(int i = (a); i < (n); i++)
#define ll long long
#define P pair<int, int>
using namespace std;

int main(){
  string n;
  cin >> n;
  rep(i,3){
    if(n.at(i) == '7'){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
