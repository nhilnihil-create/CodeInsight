// Hail god Yato
 
#include <bits/stdc++.h> 
using namespace std;
 
#define hs ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
const ll MOD = 1000000007;
const ll INF = 1e18;
const ll MAX = 100001;
//
//
void solve(){
    vector<vector<int>> vec(3, vector<int>(3));
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            cin>>vec[i][j];
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        int num;
        cin>>num;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                if(vec[i][j] == num){
                    vec[i][j] = -1;
                }
    }
    for(int i = 0; i <3 ; i++){
        int cnt = 0;
        for(int j = 0; j < 3; j++)
            cnt += vec[i][j]==-1;
        if(cnt == 3){
            cout<<"Yes\n";
            return ;
        }
    }
    for(int i = 0; i < 3; i++){
        int cnt = 0;
        for(int j = 0; j < 3; j++)
            cnt += vec[j][i]==-1;
        if(cnt == 3){
            cout<<"Yes\n";
            return ;
        }
    }
    int cnt = 0;
    for(int i = 0; i < 3; i++)
        cnt += vec[i][i]==-1;
    if(cnt == 3){
        cout<<"Yes";
        return ;
    }
    cnt = 0;
    for(int i = 0; i < 3; i++)
        cnt += vec[i][2-i]==-1;
    if(cnt == 3){
        cout<<"Yes";
        return ;
    }
    cout<<"No";
}
int main(){ 
        hs;
        ll t;
        t=1;
        // cin>>t;
        for (int i=1; i<=t; i++){
                //cout<<"Case #"<<i<<": ";
                solve();
         }
        return 0; 
}