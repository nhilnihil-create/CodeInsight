#include <bits/stdc++.h>
#define rp(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll=long long;
using P=pair<int,int>;
using G=vector<vector<int>>;

int main(){
    int n,m;
    cin >> n >> m;
    priority_queue<P> job;
    priority_queue<int> ok;
    rp(i,n){
        int a,b;
        cin >> a >> b;
        job.push(make_pair(m-a,b));
    }
    ll money=0ll;
    for(int day=m; day>=0; day--){
        bool nxt=false;
        while(!job.empty()){
            P p=job.top();
            if(p.first<day) break;
            job.pop();
            ok.push(p.second);
        }
        if(ok.empty()) continue;
        money+=(ll)ok.top();
        ok.pop();
    }
    cout << money << endl;
    return 0;
}