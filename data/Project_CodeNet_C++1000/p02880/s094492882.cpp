#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rep1(i,n) for(int i = 1; i < (n); ++i)
#define all(x) x.begin(),x.end() 
#define size(x) ll(x.size())
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
  int n;
  bool flag = false;
  cin >> n;
  rep1(i,10){
    rep1(j,10){
      if(i*j == n){
        flag = true;
        break;
      }
    }
  }
  
  if(flag){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}
