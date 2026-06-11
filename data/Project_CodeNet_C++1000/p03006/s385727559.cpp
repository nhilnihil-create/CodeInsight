#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin>>N;
    vector<int> x(N), y(N);
    rep(i,N) {
        cin>>x[i]>>y[i];
    }
    map<P, int> mp;
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            P p = make_pair(x[j]-x[i], y[j]-y[i]);
            if(p.first<0 && p.second<0){
                p.first*=-1;
                p.second*=-1;
            }
            if(p.first<0 && p.second>0){
                p.first*=-1;
                p.second*=-1;
            }
            if(p.first == 0 && p.second<0){
                p.second*=-1;
            }
            if(p.first<0 && p.second==0){
                p.first*=-1;
            }
            mp[p]++;
        }
    }
    int mx = 0;
    for(auto a : mp){
        chmax(mx, a.second);
    }
    cout<<N-mx<<endl;
}