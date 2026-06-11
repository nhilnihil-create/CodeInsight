//ヘッダー
#include<bits/stdc++.h>
using namespace std;

//型定義
typedef long long ll;

//定数
const int INF=1e+9;
const int MOD=1e+9+7;

//REPマクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define REP2(i,a,b) for(ll i=a;i<(ll)(b);i++)
#define REPD2(i,a,b) for(ll i=a;i>(ll)(b);i--)

//vectorの扱い
#define ALL(x) (x).begin(),(x).end() //sortなどの引数省略
#define SIZE(x) ((ll)(x).size()) //size
#define MAX(x) *max_element(ALL(x)) //最大値
#define MIN(x) *min_element(ALL(x)) //最小値

//グローバル変数


//ライブラリ挿入


int main(){
    int N;
    cin>>N;
    vector<vector<int>> A(N,vector<int>(N,-1));
    int tmp;
    REP(i,N){
        REP(j,N-1){
            cin>>tmp;
            tmp--;
            A[i][j]=tmp;
        }
    }
    vector<int> cnt(N,0);
    int ans=0;
    int cnt_match=0;
    int cnt_day=1;
    int aite;
    priority_queue<int> que1,que2;
    REP(i,N) que1.push(i);
    while(cnt_day>0&&cnt_match<(N*(N-1))/2){
        ans++;
        cnt_day=0;
        vector<bool> flag(N,false);
        
        if(que1.empty()){
            while(!que2.empty()){
                int i=que2.top();
                que2.pop();
                aite=A[i][cnt[i]];
                if(aite==-1) continue;
                if(flag[i]||flag[aite]) continue;
                if(A[aite][cnt[aite]]==i){
                    cnt[i]++;
                    cnt[aite]++;
                    cnt_day++;       
                    cnt_match++;
                    flag[i]=true;
                    flag[aite]=true;
                    que1.push(i);
                    que1.push(aite);
                }
            }
        }else if(que2.empty()){
            while(!que1.empty()){
                int i=que1.top();
                que1.pop();
                aite=A[i][cnt[i]];
                if(aite==-1) continue;
                if(flag[i]||flag[aite]) continue;
                if(A[aite][cnt[aite]]==i){
                    cnt[i]++;
                    cnt[aite]++;
                    cnt_day++;       
                    cnt_match++;
                    flag[i]=true;
                    flag[aite]=true;
                    que2.push(i);
                    que2.push(aite);
                }
            }
        }
        
        
        
    }
    if(cnt_day==0) cout<<-1<<endl;
    else cout<<ans<<endl;
    
}