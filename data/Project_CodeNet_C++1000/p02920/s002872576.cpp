#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef pair<int,int> P;
#define fi first
#define se second
#define pb push_back
#define all(v) (v).begin(),v.end()
const ll mod=1000000007;
const ll mod2=998244353;
const ll inf=100000000000000000;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
vector<int> dy={-1,0,1,0},dx={0,-1,0,1};
int main(){
int n;
cin>>n;
multiset<int> s;
multiset<int,greater<int>> tmp;
vector<int> a((1<<n));
for(int i=0;i<(1<<n);i++){
  cin>>a[i];
  s.insert(a[i]);
}
multiset<int>::iterator ite;
ite=s.end();
ite--;s.erase(ite);
tmp.insert((int)*ite);
for(int times=0;times<n;times++){
  vector<int> slime;
    for(auto ite=tmp.begin();ite!=tmp.end();ite++){
        auto it=s.lower_bound((int)*ite);
       // cout<<s.size()<<endl;
        if(it==s.begin()){
          cout<<"No"<<endl;
          return 0;
        }
        it--;
        s.erase(it);
        slime.push_back((int)*it);
    }
    for(int i=0;i<slime.size();i++){
            tmp.insert(slime[i]);
    }
}
cout<<"Yes"<<endl;
}