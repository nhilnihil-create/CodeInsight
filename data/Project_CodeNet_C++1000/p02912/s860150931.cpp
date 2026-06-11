#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
int main(){
    ll n,m;
    cin >> n >> m;
    priority_queue<ll> data;
    rep(i,0,n){
        ll a;
        cin >> a;
        data.push(a);
    }
    // sort(data.begin(),data.end());
    // reverse(data.begin(),data.end());
    rep(i,0,m){
        ll Max = data.top();
        data.pop();
        data.push(Max/2);
    }
    ll sum = 0;
    while(!data.empty()){
        sum += data.top();
        data.pop();
    }
    cout<<sum<<endl;

    
    return 0;
}
