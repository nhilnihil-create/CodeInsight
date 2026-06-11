#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int n;
  cin >> n;
  long long a=0,b=0,c=0,ans=1;
  long long p=1000000007;
  rep(i,n){
    long long u;
    cin >> u;
    if(a!=u&&b!=u&&c!=u)ans*=0;
    else if(a==u&&b==u&&c==u){
      ans=(ans*3)%p;
      a++;
    }
    else if(a==u&&b!=u&&c!=u){
      a++;
    }
    else if(a!=u&&b==u&&c!=u)b++;
    else if(a!=u&&b!=u&&c==u)c++;
    else if(a==u&&b==u&&c!=u){
      a++;
      ans=ans*2%p;
    }
    else if(a==u&&b!=u&&c==u){
      a++;
      ans=ans*2%p;
    }
    else if(a!=u&&b==u&&c==u){
      b++;
      ans=ans*2%p;
    }

  }
  /*if(a==b&&b==c)cout << ans << endl;
  else if(a!=b&&b!=c&&c!=a)cout << ans*6%p << endl;
  else cout << ans*3%p << endl;*/
  cout << ans << endl;
}
