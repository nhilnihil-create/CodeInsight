#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define per(i,n) for(int i=(n)-1; i>=0; i--)
using namespace std;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    int n,k;cin>>n>>k;
    
    map<char,int> score;
    string hand = "spr";
    rep(i,3)cin>>score[hand[i]];
    
    string t;cin>>t;
    vector<string> line(k);
    
    rep(i,n)line[i%k].push_back(t[i]);
    
    int ans = 0;
    
    rep(i,k){
        int len = 1;
        for(int j=1; j<line[i].size(); j++){
            if(line[i][j]==line[i][j-1])
                len++;
            else{
                ans += ((len+1)/2) * score[line[i][j-1]];
                len = 1;
            }
        }
        ans += ((len+1)/2) * score[line[i].back()];
        
    }
    
    cout << ans << endl;
    return 0;
}