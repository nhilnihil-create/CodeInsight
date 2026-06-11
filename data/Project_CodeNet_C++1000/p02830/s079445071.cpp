#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX
#define INFL LLONG_MAX
typedef long long ll;
using namespace std;

#define MOD 1000000007


int main(){


  string s,t;
  int n;
  cin >> n;
  cin >> s >> t;
    string moji="";

rep(i,n){
    moji.push_back(s.at(i));
    moji.push_back(t.at(i));

  }



  cout << moji << endl ;


  }
