#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll=long long;
using vi=vector<int>;
using vll=vector<ll>;
#define MOD 1e9+7

int main(){
    int n,k;
    cin >> n >> k;
    vll p(n);
    vll c(n);
    for(int i=0;i<n;i++){
        cin >> p[i];
        p[i]--;
    }
    for(int i=0;i<n;i++){
        cin >> c[i];
    }
    ll best_score=-1e18;

    //Pは1-Nの順列だから、どの要素も必ずループの中身
    for(int i=0;i<n;i++){
        ll now_score=0;
        int next;
        next=p[i];
        ll loop_score=c[next];
        int loop_count=1;
        while(1){
            loop_count++;
            next=p[next];
            loop_score+=c[next];
            if(next==i) break;
        }
        ll now_max=-1e18;
        ll score=0;
        if(loop_score>0){
            now_score+=loop_score*(k/loop_count);
            int temp=k%loop_count;
            if(temp==0){
                now_score-=loop_score;
                temp=loop_count;
            }
            next=i;
            for(int j=0;j<temp;j++){
                next=p[next];
                score+=c[next];
                now_max=max(now_max,score);
            }
            if(now_max>0||now_score==-1e18){
                now_score+=now_max;
            }
        }else{
            int temp=min(k,loop_count);
            next=i;
            for(int j=0;j<temp;j++){
                next=p[next];
                score+=c[next];
                now_max=max(now_max,score);
            }
            now_score+=now_max;
        }
        best_score=max(best_score,now_score);
    }
    cout << best_score << endl;
    return 0;
}