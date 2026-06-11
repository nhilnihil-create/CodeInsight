#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main() {
    long N;
    cin>>N;
    long x[N], y[N];
    for(long i=0;i<N;++i){
        cin>>x[i]>>y[i];
    }
    map<pair<long, long>, long>pqmap;
    vector<pair<long, long> >pqarr;
    pair<long, long>pq;
    long p, q;
    for(long i=0;i<N;++i){
        for(long j=i+1;j<N;++j){
            p = x[i] - x[j];
            q = y[i] - y[j];
            if(p<0){
                p *= -1;
                q *= -1;
            }
            if(p==0 & q<0) q *= -1;
            pq = make_pair(p, q);
            if(pqmap[pq]==0){
                pqarr.push_back(pq);
            }
            pqmap[pq]++;
        }
    }
    /**
    for(long i=0;i<pqarr.size();++i){
        cout<<pqarr[i].first<<" "<<pqarr[i].second<<endl;
        cout<<pqmap[pqarr[i]]<<endl;
    }
    **/
    long maxpq = 0;
    for(long i=0;i<pqarr.size();++i){
        if(maxpq < pqmap[pqarr[i]]){
            maxpq = pqmap[pqarr[i]];
            pq = pqarr[i];
        }
    }
    cout<<N-maxpq<<endl;
}
