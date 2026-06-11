#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector <int> a(n-1);
    vector <int> b(n-1);
    vector <int> c(n+1,0);
    vector <vector <int>> d;
    vector <vector <int>> hasi;
    rep(i,n+1) d.push_back(vector<int>());    
    rep(i,n+1) hasi.push_back(vector<int>());    
        

    rep(i,n-1){
        cin >> a[i] >> b[i];
        ++c[a[i]];
        ++c[b[i]];
        d[a[i]].push_back(b[i]);
        hasi[a[i]].push_back(i);
        d[b[i]].push_back(a[i]);
        hasi[b[i]].push_back(i);
    }

    int m;
    m=0;
    rep(i,n){
        m=max(m,c[i]);
    }
    queue <int> q;
    q.push(1);
    int l;
    vector <int> ans(n-1,-1);
    int k;


    while(q.size()!=0){
        int kaunt;
        kaunt=0;
        vector <int> nokori(m+1,1);
        k=q.front();
        q.pop();
        l=d[k].size();
        rep(i,l){
            if(ans[hasi[k][i]]!=-1){
                nokori[ans[hasi[k][i]]]=0;
            }
        }

        rep(i,l){
            if (ans[hasi[k][i]]==-1){
                q.push(d[k][i]);
                while(1==1){
                    if(nokori[kaunt]==1){
                        ans[hasi[k][i]]=kaunt;
                        nokori[kaunt]==0;
                        ++kaunt;
                        break;
                    }
                    ++kaunt;
                }
            }
        }




    }
    cout << m << endl;
    rep(i,n-1) cout << ans[i]+1 << endl;

    return 0;
}