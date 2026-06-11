#include <bits/stdc++.h>
using namespace std;
int main(){
    long long H,W,M;
    cin>>H>>W>>M;
    long long h[M],w[M];
    set<pair<long long,long long>>m;
    vector<long long> a(H,0);
    vector<long long> b(W,0);
    for(int i=0;i<M;i++){
        cin>>h[i]>>w[i];
        m.insert({h[i],w[i]});
        a[h[i]-1]++;
        b[w[i]-1]++;
    }
    vector<long long> c=a;
    vector<long long> d=b;
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());
    long long maxa=c[H-1],maxb=d[W-1];
    vector<long long> e;
    vector<long long> f;
    for(int i=0;i<H;i++){
        if(a[i]==maxa){
            e.push_back(i);
        }
    }
    for(int i=0;i<W;i++){
        if(b[i]==maxb){
            f.push_back(i);
        }
    }
    long long ans=maxa+maxb-1;
    for(int i=0;i<e.size();i++){
        for(int j=0;j<f.size();j++){
            if(m.find({e[i]+1,f[j]+1}) == m.end()){
                ans=maxa+maxb;
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
