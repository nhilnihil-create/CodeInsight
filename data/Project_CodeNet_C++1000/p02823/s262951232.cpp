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
  ll N, A, B; cin >> N >> A >> B;
  if (A>B) swap(A,B);

  if ((B-A)%2==0) cout << (B-A)/2 << endl;
  else {
    if (A-1<=N-B) cout << A+(B-A-1)/2 << endl;
    else cout << N-B+1+(B-A-1)/2 << endl;
  }
  

  

  // cout << fixed << setprecision(6);
  return 0;
}

