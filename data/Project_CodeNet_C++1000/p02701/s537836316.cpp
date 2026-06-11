#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P  = pair<ll,ll>;
using vi = vector<ll>;
using vv = vector<vi>;

int main(){
    int n;
    cin >> n;
    set<string> s;
    rep(i,n){
      string t;
      cin>>t;
      s.insert(t);
    }
    cout<<s.size()<<endl;
    return 0;
}
