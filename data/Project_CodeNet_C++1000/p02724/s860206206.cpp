#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int x,ure;
  cin>>x;
  ure=0;
  ure=((x/500)*1000)+(((x-(x/500)*500))/5*5);
  cout<<ure;
}