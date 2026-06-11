#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
int main(){
  long long a;
  string b;
  cin >> a >> b;
  int aa,bb,cc,dd;
  string aaa,bbb,ccc;
  aaa=b[0];
  bbb=b[2];
  ccc=b[3];
  aa=stoi(aaa)*100;
  bb=stoi(bbb)*10;
  cc=stoi(ccc);
  dd=aa+bb+cc;
  long long ans;
  ans=dd*a/100;
  cout << ans << endl;
}
