#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0;i<n;++i)
#define all(v) v.begin(), v.end()
typedef long long int ll;
typedef unsigned long long ull;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
typedef pair<ll,ll> P;
const long long MOD = 1e9+7;
const ll INF = 1LL << 60;

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    int index = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 1)index = 1;
    
    }
    bool flag = true;

    if(index == 0){
        flag = false;
    }
    index = 1;

    for(int i = 0; i < n; i++){
        if(a[i] == index){
            index++;
        }
    }

    int ans = n - (index - 1) ;
    if(flag){
        cout << ans << endl;
    }else{
        cout << -1 << endl;
    }


}