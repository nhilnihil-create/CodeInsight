#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;cin >> n;
    vector<P> p(n);
    rep(i,n){
        int x,l;
        cin >>x >> l;
        p[i].first = x+l;
        p[i].second = x-l;
    }
    sort(p.begin(),p.end());
    int cnt = 1;
    int ind = 0;
    for(int i = 1;i <= n-1;i++){
        if(p[i].second<p[ind].first) continue;
        ind = i;
        cnt ++;
    }

    cout << cnt << endl;
}
