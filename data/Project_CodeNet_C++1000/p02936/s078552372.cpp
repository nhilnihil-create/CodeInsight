#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> G;
vector<int> out_x; 
vector<int> visited;
vector<int> dist;

/*void dfs(int now, int plus){
    visited.at(now) = 1;
    out_x.at(now) += plus;
    for(int i=0; i<G.at(now).size(); i++){
        int next = G.at(now).at(i);
        if(visited.at(next)==0 && dist.at(next) > dist.at(now)){
            dfs(next, plus);
        }
    }
}*/

int main(){
    int n,q;
    cin >> n >> q;
    G.resize(n);
    out_x = vector<int>(n,0);
    dist = vector<int>(n,-1);
    for(int i=0; i<n-1; i++){
        int a,b;
        cin >> a >> b;
        a--; b--;
        G.at(a).push_back(b);
        G.at(b).push_back(a);
    }
    queue<int> que;
    vector<int> parent(n,0);
    que.push(0);
    dist.at(0) = 0;
    while(!que.empty()){
        int front=que.front();
        for(int i=0; i<G.at(front).size(); i++){
            int next=G.at(front).at(i);
            if(dist.at(next) == -1){
                dist.at(next) = dist.at(front)+1;
                que.push(next);
                parent.at(next) = front; 
            }
        }
        que.pop();
    }
    vector<int> ans(n,0);
    vector<pair<int,int>> count_plus;//i番目の命令が深さいくつのとこからか
    vector<pair<int,int>> ope;//操作の内容
    for(int i=0; i<q; i++){
        int p,x;
        cin >> p >> x;
        p--;
        //visited = vector<int>(n,0);
        //dfs(p,x);
        out_x.at(p) += x;
        pair<int, int> pa;
        pa=make_pair(dist.at(p), i);
        count_plus.push_back(pa);
        pa=make_pair(p,x);
        ope.push_back(pa);
    }
    /*
    sort(count_plus.begin(), count_plus.end());
    for(int i=0; i<q; i++){
        pair<int, int> s;
        s = count_plus.at(i);
        int index;
        index=s.second;
        s = ope.at(index);
        int place,plus;
        place = s.first;
        //plus = s.second;
        if(place == 0) continue;
        out_x.at(place) += out_x.at(parent.at(place));
    }
    */
    vector<pair<int,int>> point(n);
    for(int i=0; i<n; i++){
        pair<int,int> s=make_pair(dist.at(i), i);
        point.at(i) = s;
    }
    sort(point.begin(), point.end());
    for(int i=0; i<n; i++){
        pair<int, int> s = point.at(i);
        int place = s.second;
        if(place==0) continue;
        out_x.at(place) += out_x.at(parent.at(place));
    }
    for(int i=0; i<n; i++){
        cout << out_x.at(i) << endl;
    }
}
