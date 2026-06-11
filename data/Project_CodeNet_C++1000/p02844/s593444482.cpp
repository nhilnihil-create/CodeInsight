#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <stdio.h>
#include <list>
#include <numeric>
#include <stack>
#include <queue>
#include <tuple>
#include <bitset>
#include <map>
#include <math.h>
//ceil(a/b)   (a + (b - 1))/ b
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
typedef long long ll;
typedef pair<int,int> P;
const int inf=1000000007;
const ll mod=1000000007;
const double PI=3.14159265358979323846;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};


int main(){
  int N;
  string S;
  cin >> N >> S;
  int ans = 0;
  for(char a = '0'; a <= '9'; a++) {
	for(char b = '0'; b <= '9'; b++) {
	  for(char c = '0'; c <= '9'; c++) {
		string s;
		bool f1 = false;
		bool f2 = false;
		bool f3 = false;
		rep(i,N) {
		  if(S[i] == c && f2) f3 = true;
		  if(S[i] == b && f1) f2 = true;
		  if(S[i] == a) f1 = true;
		}
		if(f3) {
		  //		  printf("%c%c%c\n",a,b,c);
		  ans += 1;
		}

	  }	
	}	
  }
  cout << ans << endl;
  return 0;
}

