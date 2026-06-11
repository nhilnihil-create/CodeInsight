#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool compare_by_b(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second){
        return a.second > b.second;
    }else{
        return a.first < b.first;
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    priority_queue<int> q;

    pair<int, int> p[n];
    for(int i = 0; i < n; i++){
        cin >> p[i].first >> p[i].second;
        p[i].first--;
    }

    sort(p, p + n);
    /*for(int i = 0; i < n; i++){
        cout << p[i].first << " " << p[i].second << endl;
    }*/

    int now = 0;
    ll ans = 0;
    int cou = 0;
    for(int i = 0; i < m; i++){
        cou = 0;
        for(int j = now; j < n; j++){
            if(p[j].first == i){
                q.push(p[j].second);
                cou++;
            }else{
                now += cou;
                break;
            }
        }

        if(q.size() != 0){
            ans += q.top();
            q.pop();
        }
    }

    cout << ans << endl;
}