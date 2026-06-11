#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;

int main(){
    int n,q;
    cin >> n >> q;
    vector<vi> graph(n,vi());
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vi counter(n);
    for(int i=0;i<q;i++){
        int p,q;
        cin >> p >> q;
        p--;
        counter[p]+=q;
    }
    vector<bool> found(n,false);
    queue<int> que;
    que.push(0);
    found[0]=true;
    while(!que.empty()){
        int v=que.front();
        que.pop();
        for(auto x:graph[v]){
            if(found[x]) continue;
            found[x]=true;
            counter[x]+=counter[v];
            que.push(x);
        }
    }
    for(int i=0;i<n;i++){
        cout << counter[i] << " ";
    }
    cout << endl;
}