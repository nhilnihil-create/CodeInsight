#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
vector<int> x = {1,-1,0,0};
vector<int> y = {0,0,-1,1};
int main(){
    map<ll,ll> data;
    ll n;
    cin >> n;
    vector<ll> input(n);
    rep(i,0,n){
        ll a;
        cin >> a;
        input[i]=a;
        data[a]++;
    }
    ll sum=0;
    rep(i,0,n+1){
        sum += data[i]*(data[i]-1)/2;
    }
    rep(i,0,n){
        if(data[input[i]]>1){
            ll b = sum;
            ll c = data[input[i]]-1;
            cout<<b-c<<endl;
        }else{
            cout<<sum<<endl;
        }
        
    }
  return 0;
}