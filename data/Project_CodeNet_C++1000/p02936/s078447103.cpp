#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

int main(void){
    int n,q;
    cin >> n >> q;
    int a[n+1],b[n+1];
    int p[q],x[q];
    
    vector<vector<int>> s(n+1);
    vector<bool> seen;
    vector<int> num(n+1,0);
    seen.assign(n+1,false);
    
    for(int i = 1;i < n;i++){
        cin >> a[i] >> b[i];
        s[a[i]].push_back(b[i]);
        s[b[i]].push_back(a[i]);
    }
    for(int i = 0;i < q;i++){
        cin >> p[i] >> x[i];
        num[p[i]] += x[i];
    }
    
    queue<int> que;
    que.push(1);
    while(!que.empty()){
        int t = que.front();
        que.pop();
        seen[t] = 1;
        for(auto v:s[t]){
            if(!seen[v]){
                num[v] += num[t];
                que.push(v);
            }
        }
    }
    for(int i = 1;i <= n;i++)cout <<  num[i] << " ";
    
    
}