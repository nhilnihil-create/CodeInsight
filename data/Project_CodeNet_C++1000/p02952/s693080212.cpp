#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 1; i <= (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;
  
void f(int n) {
  int count;
  int temp;
  int ans = 0;
  forn(i, n){
    count = 0;
    temp = i;
    while(temp / 10 > 0){
    	temp /= 10;
      	count++;
    }
    if(count % 2 == 0){
      ans++;
      //cout << i << endl;
    }
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  f(n);
  return 0;
}