#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define ve vector

int main(){
    int n;
    cin >> n;
    ve<ve<int>> a(n,ve<int>(n-1));
    rep(i,n){
        rep(j,n-1){
            cin >> a[i][j];
            a[i][j]--;
        }
        reverse(a[i].begin(), a[i].end());
    }
    ve<P> q;
    auto check = [&](int i){
        if(a[i].size() == 0) return;
        int j = a[i].back();
        if(a[j].size()==0) return;
        if(a[j].back() == i){
            if(i>j) swap(i,j);
            P p(i,j);
            q.push_back(p);
        }
    };
    rep(i,n){
        check(i);
    }
    int day = 0;
    while(q.size()>0){
        day++;
        sort(q.begin(), q.end());
        q.erase(unique(q.begin(), q.end()), q.end());
        ve<P> prevq;
        swap(q,prevq);
        for(P p: prevq){
            int i = p.first, j = p.second;
            a[i].pop_back();
            a[j].pop_back();
            check(i);
            check(j);
        }
    }
    rep(i,n){
        if(!a[i].empty()) day = -1;
    }
    cout << day << endl;
    return 0;
}