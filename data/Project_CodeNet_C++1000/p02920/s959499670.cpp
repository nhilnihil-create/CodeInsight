#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef pair<ll,ll> P;
#define all(v) (v).begin(),v.end()
#define fi first
#define se second
set<string> c;
map<ll,ll> mp;
const ll inf=(1e18);
const ll mod=1000000007;
const ll mod2=998244353;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
int main(){
int n;
cin>>n;
int n2=1<<n;
multiset<int> s;
vector<int> a(n2);
 for(int i=0;i<n2;i++){cin>>a[i];s.insert(a[i]);}
multiset<int> q;
sort(all(a));
q.insert(a.back());
s.erase(*s.find(a.back()));
for(int i=0;i<n;i++){
   multiset<int>  p=q;
    int si=n2-1;
    while(p.size()>0&&si>=0){
        /* for(auto itt:p){
            cout<<itt<<" ";
        } 
        cout<<endl;*/
        auto ite=s.find(a[si]);
        if(ite==s.end()){
            si--;
            continue;
        }
       // cout<<a[si]<<endl;
        auto it=p.upper_bound(a[si]);
        if(it!=p.end()){
            q.insert(a[si]);
            it=p.end();it--;
            p.erase(it);
            s.erase(ite);
        }
       si--;
    }
    if(p.size()>0){
        //cout<<*p.begin()<<endl;
        cout<<"No"<<endl;
        return 0;
    }
}
cout<<"Yes"<<endl;
}



