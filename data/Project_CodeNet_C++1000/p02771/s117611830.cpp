#include <bits/stdc++.h>
using namespace std;
int main() {
  int a,b,c; cin>>a>>b>>c;
  cout<<((!(a^b)&&a-c)||(!(b^c)&&b-a)||(!(c^a)&&c-b)?"Yes":"No");
}