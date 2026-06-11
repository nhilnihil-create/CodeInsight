#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>
#define int ll

//素数判定

bool IsPrime(int num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}

main(){
  ll a,b;
  cin>>a>>b;
  vector<ll> A,B;
  for(int i = 1; i*i<=a; i++){
    if(a%i==0){
      A.push_back(i);
      A.push_back(a/i);
    }
  }
  for(int i = 1; i*i<=b; i++){
    if(b%i==0){
      B.push_back(i);
      B.push_back(b/i);
    }
  }
  map<ll,ll> mp;
  for(auto x : A){
    for(auto y : B){
      if(x==y) mp[x]=1;
    }
  }
  int ans=0;
  for(auto x : mp){
    if(x.first == 1 || IsPrime(x.first)) ans++;
  }
  cout<<ans<<endl;
}

