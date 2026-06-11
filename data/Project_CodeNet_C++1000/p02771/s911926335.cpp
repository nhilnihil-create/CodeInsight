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
  int A[3];
  rep(i,3) cin >> A[i];
  sort(A,A+3);
  if (A[0]==A[1] && A[1]!=A[2]) cout << "Yes" << endl;
  else if (A[0]!=A[1] && A[1]==A[2]) cout << "Yes" << endl;
  else cout << "No" << endl;




  // cout << fixed << setprecision(6);
  return 0;
}

