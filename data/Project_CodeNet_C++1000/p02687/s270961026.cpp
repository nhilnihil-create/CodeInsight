#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<ll,int> P;

struct edge {int to; ll cost; };

int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  string s;
  cin >> s;
  if(s[1]=='B') s[1]='R';
  else s[1] = 'B';
  cout << s << endl;
  return 0;
}
