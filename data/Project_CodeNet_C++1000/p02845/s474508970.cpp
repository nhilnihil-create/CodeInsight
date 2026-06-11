#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int mod=1000000007;
  int n;
  cin >> n;
  int to=n;
  vector<int>a(n);
  rep(i,n){
    cin>>a.at(i);
  }
  long ans=1;
  int fi=-1;
  int se=-1;
  int th=-1;
  rep(i,n){
    int co=0;
    if(a.at(i)==fi+1&&a.at(i)==se+1&&a.at(i)==th+1){
      co=3;
      fi++;
    }
    else if(a.at(i)==fi+1&&a.at(i)==se+1&&a.at(i)!=th+1){
      co=2;
      fi++;
    }
    else if(a.at(i)==fi+1&&a.at(i)!=se+1&&a.at(i)==th+1){
      co=2;
      fi++;
    }
    else if(a.at(i)!=fi+1&&a.at(i)==se+1&&a.at(i)==th+1){
      co=2;
      se++;
    }
    else if(a.at(i)!=fi+1&&a.at(i)!=se+1&&a.at(i)==th+1){
      co=1;
      th++;
    }
    else if(a.at(i)!=fi+1&&a.at(i)==se+1&&a.at(i)!=th+1){
      co=1;
      se++;
    }
    else if(a.at(i)==fi+1&&a.at(i)!=se+1&&a.at(i)!=th+1){
      co=1;
      fi++;
    }
    else{
      ans=0;
      break;
    }
    ans*=co;
    ans%=mod;
  }
  cout<<ans<<endl;  
}