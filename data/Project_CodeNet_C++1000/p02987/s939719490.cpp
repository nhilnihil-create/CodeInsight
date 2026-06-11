#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  vector<char> s(4);
  rep(i,4) cin >> s.at(i);

  if(s.at(0)==s.at(1)&&s.at(1)==s.at(2)&&s.at(2)==s.at(3)) cout << "No";
  else if(s.at(0)==s.at(1)&&s.at(2)==s.at(3)) cout << "Yes";
  else if(s.at(0)==s.at(2)&&s.at(1)==s.at(3)) cout << "Yes";
  else if(s.at(0)==s.at(3)&&s.at(1)==s.at(2)) cout << "Yes";
  else cout << "No";
  
}