#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)

int64_t gcd(int64_t a, int64_t b);
int64_t lcm(int64_t a, int64_t b);

int main(){
  int64_t n, m;
  cin >> n >> m;

  int guu=0;

  vector<int64_t> a(n);
  vector<int64_t> b(n);
  rep(i,n) {
    cin >> a.at(i);
    b.at(i) = a.at(i)/2;
    if(b.at(i)%2==0) guu++;
  }
  
  int64_t saidai;
  int64_t saisho = b.at(0);

  int64_t ans = 0;
  if(guu!=0&&guu!=n) cout << 0;
  else{
    for(int i=1; i<n; i++){
      saisho = lcm(saisho, b.at(i));
    }
  

  bool frag=true;
  
  rep(i,n){
    if((saisho/b.at(i))%2==0){frag=false; break;}
  }

  if(guu==0){
    if(frag) cout<<((m/saisho)+1)/2;
    else cout<<(m/saisho)/2;
  }
  if(guu==n){
    bool frag2=true;
    rep(i,n){
      if((saisho/b.at(i))%2==0){frag2=false; break;}
    }
    if(frag&&frag2)cout<<((m/saisho)+1)/2;
    else if(frag2) cout<<(m/saisho)/2;
    else cout << 0;
  }

}
}

int64_t gcd(int64_t a, int64_t b){
  if(a%b==0) return b;
  else return gcd(b, a%b);
}

int64_t lcm(int64_t a, int64_t b){
  return a*b/gcd(a,b);
}
