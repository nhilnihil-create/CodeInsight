#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LINF = 1e18;
const int INF = 1e9;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int N;
    cin>>N;
    vector<pair<int,int>> work;
    rep(i,N){
        int a,b;
        cin>>a>>b;
        work.push_back(pair<int,int>(b,a));
    }
    sort(work.begin(),work.end());
    ll cnt=0;
    rep(i,N){
        cnt+=work[i].second;
        if(cnt>work[i].first){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}