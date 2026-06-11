#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
typedef long long ll;
int main(void){
    int n;cin>>n;
    vector<vector<int>> a(n,vector<int>(n-1));
    rep(i,n){
        rep(j,n-1){
            cin>>a[i][j];
            a[i][j]--;
        }
    }
    vector<int> now(n,0);//今i人目の人は何回戦ったか
    int fin=0;//n-1回戦った人の数
    int res=1;//fin=nになるまでに何日かかったか
    queue<int> que;
    rep(i,n) que.push(i);
    while(que.size()>0){
        vector<bool> fight(n,true);
        bool match=false;//1戦もできなかった場合-1を返すフラグ
        queue<int> que2;
        while(que.size()){
            int i=que.front();
            que.pop();
            if(now[i]==n-1) continue;
            int op=a[i][now[i]];
            if(a[op][now[op]]==i&&fight[op]&&fight[i]){
                match=true;
                now[i]++;
                now[op]++;
                if(now[i]==n-1)fin++;
                if(now[op]==n-1)fin++;
                fight[i]=false;
                fight[op]=false;
                que2.push(op);
                que2.push(i);
            }
        }
        swap(que,que2);
        if(!match){
            cout<<-1<<endl;
            return 0;
        }else if(fin==n){
            cout<<res<<endl;
            return 0;
        }
        res++;
    }
    return 0;
}