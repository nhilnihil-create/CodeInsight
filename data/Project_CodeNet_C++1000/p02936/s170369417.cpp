#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
typedef long long ll;

int main(){
    int N ,Q;
    cin >> N >> Q;
    vector<int> w(N+1,0);
    vector<int> v[N+1];
    rep(i,N-1){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    rep(i,Q){
        int p,x;
        cin >> p >> x;
        w[p]+=x;
    }

    queue<int> que;
    vector<bool> visit(N+1,false);
    que.push(1);
    while(!que.empty()){
        int cur=que.front();
        visit[cur]=true;
        que.pop();
        for(int next : v[cur]){
            if(visit[next]) continue;
            
            w[next]+=w[cur];
            que.push(next);
        }
    }

    rep2(i,1,N+1) cout << w[i] << " ";
    cout << endl;

}
