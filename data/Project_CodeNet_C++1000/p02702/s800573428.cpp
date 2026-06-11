#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 1001001001;



//2910201
//size = 4,5,6,7,8,9,....s.size();
//serch_times = n-3, n-4, n-5, ...1= O(n^2)
//for(int k = 4; k<n; k++)
//for(i = 0; i < n; i++)
//for(j=i; j<=k; j++)


//200000/2019 ~ 100; 

//x -> x-1 + x-2 + x -3 + ......1 = x*(x-1)/2

int main(){
  string s;
  cin >> s;

  int n = s.size();
  vector<int> val(2019,0);
  int c = 0;
  int fac = 1;
  val[c]++;
  rep(i,n){
    c += (s[n-1-i] - '0')*fac;
    c %= 2019;
    val[c]++;
    fac *= 10;
    fac %= 2019;
  }

  int ans = 0;
  rep(i,2019) ans += val[i]*(val[i]-1)/2;
  cout << ans << endl;
}
