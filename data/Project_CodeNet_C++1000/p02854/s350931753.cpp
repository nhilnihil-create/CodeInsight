#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  long to=0;
  vector<long>x(n),y(n);
  rep(i,n){
    cin>>x.at(i);
    to+=x.at(i);
    y.at(i)=to;
  }
  long ch=500000000000000;
  rep(i,n){
    ch=min(ch,abs(to-y.at(i)*2));
  }  
  cout<<ch<<endl;  
}




