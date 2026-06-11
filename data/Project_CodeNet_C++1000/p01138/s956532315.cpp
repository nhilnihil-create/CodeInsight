#include <bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i++)
#define ALL(a) (a).begin(),(a).end()
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define ll long long
#define ull unsigned long long
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
 
using namespace std;
const int TIME = 24*60*60;
int train_t[TIME+1]; 

int timeset(string s,int mode){
  int h = (s[0] - '0') * 10 + s[1] - '0';
  int m = (s[3] - '0') * 10 + s[4] - '0';
  int ss = (s[6] - '0') * 10 + s[7] - '0';
  int t = h * 60 * 60 + m * 60 + ss;
  if(mode)train_t[t] += 1;
  else train_t[t] -= 1;
}

int main(){
  int n;
  while(cin >> n){
    if(!n)break;
    REP(i,TIME)train_t[i] = 0;
    string s;
    REP(i,n){
      cin >> s;
      timeset(s,1);
      cin >> s;
      timeset(s,0);
    }
    int max_vehicle = 0;
    REP(i,TIME){
      train_t[i+1]+= train_t[i];
      max_vehicle = max(max_vehicle,train_t[i+1]);
    }
    cout << max_vehicle << endl;
  }
  return 0;
}