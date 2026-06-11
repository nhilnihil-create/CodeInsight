#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
typedef long long ll;

int main(){
    int N,M;
    cin >> N >> M;
    vector<pair<int,int>> AB(N);
    rep(i,N) cin >> AB[i].first >> AB[i].second;

    sort(AB.begin(),AB.end());
    priority_queue<int> que;
    int cnt=0;
    ll ans=0;
    rep2(i,1,M+1){
        while(AB[cnt].first<=i){
            que.push(AB[cnt].second);
            cnt++;
        }
        if(!que.empty()){
            ans+=que.top();
            que.pop();
        }
        
    }
    cout << ans << endl;
}