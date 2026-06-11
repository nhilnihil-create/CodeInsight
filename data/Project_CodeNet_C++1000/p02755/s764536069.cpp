#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
 
int main(){
  int A,B;
  cin>>A>>B;
  rep(i,1001){
    if(i*8/100==A&&i/10==B){
      cout<<i<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;
}