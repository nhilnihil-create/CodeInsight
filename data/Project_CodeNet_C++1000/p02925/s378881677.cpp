#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
int indexed[1005];
int DAY[1005];
int main(){
    int n;cin >> n;
    vector<vector<int>> a(n,vector<int>(n-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            cin >> a[i][j];
            a[i][j]--;
        }
    }
    queue<P> q;
    for(int i=0;i<n;i++){
        int enemy=a[i][0];
        indexed[i]=0;
        if(enemy>i&&a[enemy][0]==i) q.push({i,enemy}); // swapしなくて済む
    }
    while(!q.empty()){
        int me=q.front().first,enemy=q.front().second;
        q.pop();
        int day=max(DAY[me],DAY[enemy])+1;
        DAY[me]=day;
        DAY[enemy]=day;
        indexed[me]++;
        indexed[enemy]++;
        if(indexed[me]+1<n){
            int enemy2=a[me][indexed[me]];
            if(a[enemy2][indexed[enemy2]]==me){
                q.push({me,enemy2});
            }
        }
        if(indexed[enemy]+1<n){
            int enemy2=a[enemy][indexed[enemy]];
            if(a[enemy2][indexed[enemy2]]==enemy){
                q.push({enemy,enemy2});
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(indexed[i]+1<n){
            cout << -1 << endl;
            return 0;
        }
        ans=max(ans,DAY[i]);
    }
    cout << ans << endl;
    return 0;
}