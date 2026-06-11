#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF = 1e9;
const int MOD = 1000000007;

 
int main() {
        int n;
        cin >> n;
        vector<vector<int>> a(n,vector<int>(n-1,0));
        rep(i,n){
                rep(j,n-1){
                        cin >> a[i][j];
                        a[i][j] --;
                }
                reverse(a[i].begin(),a[i].end());
        }

        vector<P> q;

        auto ok = [&](int i){
                if(a[i].size() == 0) return;
                int j = a[i].back();
                if(a[j].back() == i){
                        if(i > j ) swap(i,j);
                        q.push_back(P(i,j));
                }
        };

        int day = 0;
        rep(i,n){
                ok(i);
        }
        while(!q.empty()){
                day ++;
                vector<P> prevq;
                sort(q.begin(),q.end());
                q.erase(unique(q.begin(),q.end()),q.end());
                swap(q,prevq);
                for(P game:prevq){
                        a[game.first].pop_back();
                        a[game.second].pop_back();
                }
                for(P game:prevq){
                        ok(game.first);
                        ok(game.second);
                }
        }

        rep(i,n){
                if(a[i].size() != 0){
                        cout << -1 << endl;
                        return 0;
                }
        }

        cout << day << endl;

        return 0;
}



