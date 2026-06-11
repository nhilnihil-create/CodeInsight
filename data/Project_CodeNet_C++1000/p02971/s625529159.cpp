#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);

int main() {
int n;
cin >> n;
vector<int> b(n);
rep(i,n) cin >> b.at(i);
vector<int> a = b;
sort(a.begin(),a.end());
if(a.at(n-1)==a.at(n-2)){
  rep(i,n)cout << a.at(n-1) << endl;
}else{
  rep(i,n){
    if(b.at(i) == a.at(n-1)) cout << a.at(n-2) << endl;
    else cout << a.at(n-1) << endl;
  }
}

}
