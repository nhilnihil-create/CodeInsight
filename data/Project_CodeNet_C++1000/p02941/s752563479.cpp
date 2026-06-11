#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef pair<ll,ll> P;
#define fi first
#define se second
#define all(v) (v).begin(),v.end()
set<string> c;
const ll mod=1000000007;
const ll mod2=998244353;
const ll inf=100000000000000000;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
vector<int> dy={-1,0,1,0},dx={0,-1,0,1};
int main(){
int n;
cin>>n;
vector<ll> a(n),b(n);
for(int i=0;i<n;i++)cin>>a.at(i);
for(int i=0;i<n;i++)cin>>b.at(i);
int i=0;
bool check=true;
ll cnt=0;
while(1){
if(b.at(i)-((i>0?b.at(i-1):b.at(n-1))+(i<n-1?b.at(i+1):b.at(0)))>=a.at(i)){
/* for(int i=0;i<n;i++)cout<<b.at(i)<<" ";
cout<<endl;*/
check=false;
ll nowcnt,bet;
bet=((i>0?b.at(i-1):b.at(n-1))+(i<n-1?b.at(i+1):b.at(0)));
nowcnt=((b.at(i)-a.at(i))/bet);
cnt+=nowcnt;
b.at(i)-=nowcnt*bet;
}
if(i==n-1&&!check)check=true;
else if(i==n-1&&check){
  for(int i=0;i<n;i++){
      if(a.at(i)!=b.at(i)){cout<<-1<<endl;return 0;}
  }
  cout<<cnt<<endl;
  return 0;
}
i++;
i%=n;
}

}

