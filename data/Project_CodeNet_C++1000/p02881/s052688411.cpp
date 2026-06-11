#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<=(n);i++)
#define pb push_back
#define mod 1000000007
#define INF 2000000000
typedef long long ll;
bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first){
        return a.first < b.first;
        
    }else{
        return a.second < b.second;
    }
}
// 入力



int main() {
     ll N;
    
    cin >>N;
    ll n = sqrt(N)+1;
    ll max=1;
    rep2(i,n){
        if((N%i) == 0){
            max = i;
        }
    }
    ll ans = max + N/max -2;
    cout << ans << endl;
    
    
    return 0;
    

}