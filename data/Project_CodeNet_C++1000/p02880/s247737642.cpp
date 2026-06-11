#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;
  
void f(int n) {
  for(int i = 1; i < 10; i++){
  	for(int j = 1; j < 10; j++){
    	if(i * j == n){
          cout << "Yes" << endl;
          return;
   		}	
    }
  }
  cout << "No" << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  f(n);
  return 0;
}