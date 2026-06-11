#include <bits/stdc++.h>
using namespace std;

int C(int x,int y){/*xCy,x≧y≧0*/if(y==0)return 1;return x*C(x-1,y-1)/y;}

int main() {
  int n,m;cin>>n>>m;
  cout<<C(n,2)+C(m,2)<<endl;
}
