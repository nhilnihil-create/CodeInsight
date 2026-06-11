#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define SZ(x) ((int)(x).size())
int gcd(int a,int b){return b?gcd(b,a%b):a;}
const double pi=acos(-1);


 
int main() {
  int n;
  cin >> n;
  
  vector<int> a = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
  
  cout << a.at(n-1) << endl;
}
