#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include<set> 
#include<math.h>
#define pai arccos(-1);
#define keta(n) cout << fixed << setprecision((n));
#define ll long long;
int main(){
  string t;
  cin>>t;
  for(int i=0;i<t.size();i++){
    if(t[i]=='?'){
      t[i]='D';
    }
  }
  for(int i=0;i<t.size();i++){
    cout<<t[i];
  }
}
