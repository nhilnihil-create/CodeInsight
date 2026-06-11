#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>


int main(){
  int N; cin >> N;
  int h[N]; rep(i,N) cin >> h[i];

  bool flag = true;
  bool uno = false;
  rep(i,N){
    if (i>=1 && h[i]<=h[i-1]-2) flag = false;
    else if (i>=2 && h[i]==h[i-1]-1){
      if (uno) flag = false;
      else uno = true;
    }
    else if (i>=2 && h[i]>h[i-1]) uno = false;
    else continue;

  }
  cout << (flag ? "Yes" : "No")  << endl;


  

  // cout << fixed << setprecision(6);
  return 0;
}

