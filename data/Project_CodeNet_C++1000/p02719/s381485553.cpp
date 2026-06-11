#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n) ;i++)

using namespace std;
using p=pair<int,int>;
typedef long long ll;

int main() {
  ll n,k;
  cin >> n >> k;

 cout<<min(n%k,k-(n%k))<<endl;




    return 0;
}

