#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<int> memo(3, -1);
    
    for(int i=0; i<m; i++){
        int s, c; cin >> s >> c;
        if(memo[s-1] == -1){
            memo[s-1] = c;
        }else if(memo[s-1] == c){
            continue;
        }else if(memo[s-1] != c){
            cout << -1 << endl;
            return 0;
        }
    }
    int ans=0;
    if(n==1){
        if(memo[0]==-1) ans = 0;
        else ans = memo[0];
    }else if(n==2){
        if(memo[0]==-1 && memo[1]==-1) ans = 10;
        if(memo[0]==-1 && memo[1]!=-1) ans = 10 + memo[1];
        if(memo[0]!=-1 && memo[1]==-1) ans = memo[0]*10;
        if(memo[0]!=-1 && memo[1]!=-1) ans = memo[0]*10 +memo[1];
    }else if(n==3){
        if(memo[0]==-1 && memo[1]==-1 && memo[2]==-1) ans = 100;
        if(memo[0]==-1 && memo[1]==-1 && memo[2]!=-1) ans = 100 + memo[2];
        if(memo[0]==-1 && memo[1]!=-1 && memo[2]==-1) ans = 100 + memo[1]*10;
        if(memo[0]!=-1 && memo[1]==-1 && memo[2]==-1) ans = memo[0]*100;
        if(memo[0]==-1 && memo[1]!=-1 && memo[2]!=-1) ans = 100 + memo[1]*10 + memo[2];
        if(memo[0]!=-1 && memo[1]==-1 && memo[2]!=-1) ans = memo[0]*100 + memo[2];
        if(memo[0]!=-1 && memo[1]!=-1 && memo[2]==-1) ans = memo[0]*100 + memo[1]*10;
        if(memo[0]!=-1 && memo[1]!=-1 && memo[2]!=-1) ans = memo[0]*100 + memo[1]*10 +memo[2];
    }
    
    
    if((n!=1 && memo[0]==0 && memo[1]!=0 && memo[2]!=0)|| (n!=1 && memo[0]==0 && memo[1]==0 && memo[2]!=0)){
        cout << -1 << endl; return 0;
    }
    
    cout << ans << endl;
    return 0;
}