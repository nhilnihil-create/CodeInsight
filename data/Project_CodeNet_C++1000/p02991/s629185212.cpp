#include<bits/stdc++.h>
using namespace std;
int main(){
    long n,m;
    cin >> n >> m;
    vector<set<int> >move(n);
    int u,v;
    for(int i=0;i<m;i++){
        cin >> u >> v;
        u--;
        v--;
        move[u].insert(v);
    }
    int s,t;
    cin >> s >> t;
    s--;
    t--;
    int ans = -3;
    vector<vector<bool> >went(n,vector<bool>(3,false));
    queue<pair<int,int> >que;
    que.push(make_pair(s,0));
    while(!que.empty()){
        int tmp = que.front().first;
        int moved = que.front().second;
        que.pop();
        if(tmp == t && moved%3 == 0){
            ans = moved;
            break;
        }

       
        if(!went[tmp][moved%3]){
            for(auto j:move[tmp]){
                que.push(make_pair(j,moved+1));
            }
        }

       went[tmp][moved%3] = true;
    
        
        
       
    }
    cout << ans/3 << endl;

}
