#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll A;
  cin>>A;
  char a,b,c,d;
  cin>>a>>b>>c>>d;
  ll B=(a-'0')*100+(c-'0')*10+(d-'0');

  
  cout<<A*B/100<<endl;
}
