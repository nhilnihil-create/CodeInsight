#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()
#define endl "\n"

int_fast64_t gcd(int_fast64_t a,int_fast64_t b){
  if(b==0)return a;
  return gcd(b,a%b);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin>>N;
  vector<int>A(N);
  for(int i=0;i<N;i++)cin>>A[i];
  sort(rng(A));

  vector<int>a(1000001);
  vector<bool>isprime(1000001,true);
  isprime[0]=isprime[1]=false;
  for(int i=0;i<=1000000;i++){
    if(isprime[i])for(int j=i+i;j<=1000000;j+=i){
      isprime[j]=false;
      a[j]=i;
    }
  }

  vector<vector<pii>>div(1000001);
  for(int i=0;i<=1000000;i++){
    int n=i;
    map<int,int>ans;
    while(a[n]!=0){
      ans[a[n]]++;
      n=n/a[n];
    }
    if(n!=0&&n!=1)ans[n]++;
    for(auto it:ans)div[i].push_back({it.first,it.second});
  }

  vector<int>prime;
  for(int i=0;i<=1000000;i++)if(isprime[i])prime.push_back(i);

  bool pairwise=true;
  vector<int>x(1000001,0);

  for(auto it:div[A[0]])x[it.first]=max(x[it.first],it.second);

  for(int i=0;i<N-1;i++){
    for(auto it:div[A[i+1]])if(min(x[it.first],it.second)!=0)pairwise=false;
    for(auto it:div[A[i+1]])x[it.first]=max(x[it.first],it.second);
  }

  int GCD=A[0];
  for(int i=0;i<N-1;i++)GCD=gcd(GCD,A[i+1]);
  bool setwise=(GCD==1);

  if(pairwise)cout<<"pairwise coprime"<<endl;
  else if(setwise)cout<<"setwise coprime"<<endl;
  else cout<<"not coprime"<<endl;

  return 0;
}
