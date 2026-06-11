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
    ll N,cnt=0;
    
    cin >>N;
    vector<ll>L(N);
    rep(i,N){
        cin >> L[i];
    }
    sort(L.begin(), L.end());

    rep(i,N){
        for(int j = i+1;j<N; j++ ){
            cnt += lower_bound(L.begin()+j+1, L.end(), L[i] + L[j]) - L.begin() -j-1;
        }
    }




    cout << cnt << endl;
    
    
    return 0;
    

}