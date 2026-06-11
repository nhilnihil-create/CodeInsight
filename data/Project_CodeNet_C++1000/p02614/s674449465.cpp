#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int h, w, k;
    cin>>h>>w>>k;
    string c[h];
    rep(i, h){
        cin>>c[i];
    }

    deque<int> qh;
    deque<int> qw;

    rep(i, h) qh.push_back(0);
    int ans=0;
    while(!(qh.empty())){
        for(int i=qh.size(); i<h; i++) qh.push_back(0);
        rep(i, w) qw.push_back(0);
        while(!(qw.empty())){
            int sum=0;
            for(int i=qw.size(); i<w; i++) qw.push_back(0);
            rep(i, h)rep(j, w){
                if(c[i][j]=='#'){
                    if(qh[i]!=1 && qw[j]!=1) sum++;
                } 
            }
            while(qw.back()==1){
                qw.pop_back();
                if(qw.empty()) break;
            }
            if(!(qw.empty())){
                qw.pop_back();
                qw.push_back(1);
            }
            if(sum==k) ans++;
        }

        while(qh.back()==1){
            qh.pop_back();
            if(qh.empty()) break;
        }
        if(!(qh.empty())){
            qh.pop_back();
            qh.push_back(1);
        }
    }
    cout<<ans<<endl;
    return 0;
}