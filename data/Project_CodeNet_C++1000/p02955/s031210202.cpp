#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vin=vector<int>;
using vll=vector<long long>;
using vvin=vector<vector<int>>;
using vvll=vector<vector<long long>>;
using vstr=vector<string>;
using vvstr=vector<vector<string>>;
using vch=vector<char>;
using vvch=vector<vector<char>>;
using vbo=vector<bool>;
using vvbo=vector<vector<bool>>;
using vpii=vector<pair<int,int>>;
using pqsin=priority_queue<int,vector<int>,greater<int>>;
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(s);i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define decp(n) cout<<fixed<<setprecision((int)n)
const ll inf=1e9+7;
const ll INF=1e18;

vll divide;

void divisor(ll x){
    for(ll i=1;i*i<=x;i++){
        if(x%i==0){
            divide.push_back(i);
            if(i*i!=x)divide.push_back(x/i);
        }
    }
    return;
}

int main(){
    int n,k;cin>>n>>k;
    vin a(n);
    int sum=0;
    rep(i,n){
        cin>>a[i];
        sum+=a[i];
    }
    divisor(sum);
    sort(all(divide));reverse(all(divide));
    int tmp;
    rep(i,divide.size()){
        tmp=divide[i];
        vin r(n);
        rep(i,n)r[i]=a[i]%tmp;
        sort(all(r));
        rep(i,n-1)r[i+1]+=r[i];
        rep(j,n){
            if(tmp*(n-j-1)==r[n-1]&&r[j]<=k){//r[i]==d*(n-i-1)-(r[n]-r[i])
                cout<<divide[i]<<endl;
                return 0;
            }
        }
    }
}