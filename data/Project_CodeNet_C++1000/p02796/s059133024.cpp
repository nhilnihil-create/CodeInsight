#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 1000000000;

int main(){
    int n; cin >> n;
    vector<int> x(n),l(n),left(n),right(n);
    for(int i=0;i<n;++i) cin >> x[i] >> l[i];
    vector <pair<int,int> > p(n);
    for(int i=0;i<n;++i){
        left[i]=x[i]-l[i];
        right[i]=x[i]+l[i];
        p[i] = make_pair(right[i],left[i]);
    }
    int ans=0;
    int cur = -MAX_V;
    sort(p.begin(),p.end());
    for(int i=0;i<n;++i){
        if(cur<=p[i].second){
            ans++;
            cur = p[i].first;
        } 
    }
    cout << ans << endl;
    return 0;
}