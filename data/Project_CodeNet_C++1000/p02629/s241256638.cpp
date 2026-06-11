#include<iostream>
using namespace std;
using ll = long long;

int main() {
  ll N,R=26,C=1,i;
  cin>>N;
  while((N-1)/R>0) {
    N-=R;
    R*=26;
    C++;
  }
  string ans = "";
  N--;
  for (i=0;i<C;i++) {
    char c = ('a' + (N%26));
    ans = c + ans;
    N/=26;
  }
  cout<<ans<<endl;
  return 0;
}
