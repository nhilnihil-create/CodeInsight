#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
  int t,m,n;
  cin >> n >> m >> t;
  if(n==m){ if(t!=m) cout << "Yes";
          else cout << "No";
          }
  else if(m==t){if(n!=m) cout << "Yes";
          else cout << "No";}
  else if(n==t){if(n!=m) cout << "Yes";
          else cout << "No";}
  else cout << "No";

}