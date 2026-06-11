#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i< (n) ; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int main(){
  int n,i=0,s=1;
  cin >> n;
 while(s!=0)
 {
      i++;
 	s=n*i;
   s=s%360;

 }
  cout << i <<endl;
    return 0;
}