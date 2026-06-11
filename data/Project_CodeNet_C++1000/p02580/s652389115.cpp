#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[300001];
int b[300001];
map<int,vector<int>> ma;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int h,w,m; cin>> h >> w >> m;

    
    
    for(int i=0; i<m; i++){
        int x,y; cin>> x >> y;
        ma[x].push_back(y);    
        a[x] += 1; b[y] += 1;        
    }

    int cnt = 0;
    for(int i=1; i<=w; i++){
        cnt = max(cnt, b[i]);
    }

    int mc = 0;
    for(int i=1;i<=w;i++){
        if(cnt == b[i])mc += 1;
    }


    int ans = 0;
    for(int i=1; i<=h; i++){
        int ret= 0 ;

        for(int j=0; j<ma[i].size(); j++){
            if(b[ma[i][j]] == cnt)ret += 1;
        }

        if(ret == mc){
            ans = max(ans , a[i] + cnt - 1);
        }else{
            ans = max(ans , a[i] + cnt);
        }
    }

    cout << ans <<'\n';
    






}
