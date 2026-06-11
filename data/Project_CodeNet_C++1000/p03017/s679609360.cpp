#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)
typedef pair<int, int> p;

bool check(int a, int b, string s){ //a文字目からb文字目までについて(0-index)
  bool f = true; 
  for(int i = a; i<b; i++){
    if(s.at(i)=='#' && s.at(i+1)=='#'){
      f= false;
      break;
    }
  }
  return f;
}
bool check2(int a, int b, string s){ //d文字目の前後について(0-index)
  bool f = false;
  for(int i = a; i<b+1;i++){
  if(s.at(i-1)=='.' && s.at(i)=='.' && s.at(i+1)=='.') {
    f = true;
  }
}
  return f;
}

int main(){
  
	int n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  string s;
  cin >> s;
  bool f = true;
  f = check(b-1, d-1, s);
  if(f){f=check(a-1, c-1, s);}
  if(f&&c>d){
  f = check2(b-1, d-1, s);
  }
  
  
  if(f) cout <<"Yes" << endl;
  else cout << "No" << endl;
}

