#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> PLL;
typedef pair<P,P> PP;
typedef vector<ll> VECLL;
typedef vector<P> VECP;
typedef priority_queue<P,VECP,greater<P> > PQP;
typedef priority_queue<ll, VECLL, greater<ll> > PQll;

#define rep(i,a,n) for(ll i = a;i < n;i++)   
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue; 
#define LINF (ll)1e18
#define INF (int)1e9
#define fs first
#define sc second

int main(){
    ll n,k;
    cin >> n >> k;
    ll a[n] = {};
    rep(i,0,n){
        cin >> a[i];
        a[i]--;
    }
    vector<ll> vec;
    bool is_visited[n] = {false};

    ll index = 0;
    rep(i,0,n){
        if(is_visited[a[index]]){
            rep(j,0,vec.size()){
                if(vec[j] == a[index]){
                    if(j > 0) vec.erase(vec.begin(),vec.begin()+j);
                    break;
                }
            }
            break;
        }
        index = a[index];
        vec.push_back(index);
        is_visited[index] = true;
        k--;
        if(k == 0){
            cout << index+1 << endl;
            return 0;
        }
    }

    if(k % vec.size() != 0) cout << vec[k % vec.size() - 1]+1 << endl;
    else cout << vec[vec.size()-1]+1 << endl;

}
