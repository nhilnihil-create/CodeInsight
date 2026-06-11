#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin>>n;
  vector<int> l(n);
  rep(i, n) cin>>l.at(i);
  sort(l.begin(), l.end());
  long long ans = 0;
  int a,b,c;
  for(int i=0; i<n-2; i++){
    a=l.at(i);
    for(int j=i+1; j<n-1; j++){
      b=l.at(j);
      for(int k=j+1; k<n; k++){
        c=l.at(k);
        if(c<a+b && b-a<c){
          ans++;
        }
      }
    }
  }
  cout<<ans<<endl;
}