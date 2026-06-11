#include<bits/stdc++.h>
using namespace std;

#define lld long long
#define pi pair<int,int>
#define pl pair<lld,lld>
#define mem0(x) memset(x,0,sizeof(x))
#define fillnum(x,n) fill(begin(x),end(x),n)
#define asort(x) sort(x.begin(),x.end())
#define dsort(x,t) sort(x.begin(),x.end(),greater<t>())

lld gcd(lld a, lld b) {
    if (a < b) {
        a ^= b;
        b ^= a;
        a ^= b;
    }
    
    return b ? gcd(b, a % b) : a;
}

vector< lld > prime_factor(lld n) {
  vector< lld > ret;
  for(lld i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret.push_back(i);
      n /= i;
    }
  }
  if(n != 1) ret.push_back(n);
  return ret;
}

int main() {
    lld A,B;
    cin >> A >> B;
    lld m = gcd(A,B);
    vector<lld> prime = prime_factor(m);
    sort(prime.begin(),prime.end());
    prime.erase(std::unique(prime.begin(), prime.end()), prime.end());
    cout << prime.size()+1 << endl;
}