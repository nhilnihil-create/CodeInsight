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
    vector<ll> d(N); 
    rep(i,N){
        cin >> d[i];
    }
    ll sum = 0;
    rep(i,N){
        rep(j,N-i-1){
            sum += d[i]*d[j+i+1];
        }
    }
    cout << sum << endl;
    
    
    return 0;
    

}