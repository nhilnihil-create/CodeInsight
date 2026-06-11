#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<vector<int> > v(n);
    pair<int, int> p[n - 1];
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if(a < b){
            p[i].first = a;
            p[i].second = b;
        }else{
            p[i].first = b;
            p[i].second = a;
        }
        v[p[i].first].push_back(p[i].second);
        v[p[i].second].push_back(p[i].first);
    }

    int max = -1;
    int poj = -1;

    for(int i = 0; i < n; i++){
        int t = v[i].size();
        if(t > max){
            max = t;
            poj = i;
        }
    }

    cout << max << endl;

    queue<int> q;
    q.push(poj);
    map<pair<int, int>, int> m;
    int flag[n], che[n];
    for(int i = 0; i < n; i++){
        flag[i] = 0;
        che[i] = 0;
    }

    che[poj] = 1;

    while(!q.empty()){
        int t = q.front();
        q.pop();
        int cou = 1;
        for(int i = 0; i < v[t].size(); i++){
            if(che[v[t][i]] == 0){
                che[v[t][i]] = 1;
                if(t < v[t][i]){
                    if(flag[t] == 0){
                        m[make_pair(t, v[t][i])] = cou;
                        flag[v[t][i]] = cou;
                    }else{
                        if(cou != flag[t]){
                            m[make_pair(t, v[t][i])] = cou;
                            flag[v[t][i]] = cou;
                        }else{
                            cou++;
                            m[make_pair(t, v[t][i])] = cou;
                            flag[v[t][i]] = cou;
                        }
                    }
                }else{
                    if(flag[t] == 0){
                        m[make_pair(v[t][i], t)] = cou;
                        flag[v[t][i]] = cou;
                    }else{
                        if(cou != flag[t]){
                            m[make_pair(v[t][i], t)] = cou;
                            flag[v[t][i]] = cou;
                        }else{
                            cou++;
                            m[make_pair(v[t][i], t)] = cou;
                            flag[v[t][i]] = cou;
                        }
                    }
                }
                q.push(v[t][i]);
                cou++;
            }
        }
    }

    for(int i = 0; i < n - 1; i++){
        auto itr = m.find(p[i]);
        cout << itr->second << endl;
    }  
}