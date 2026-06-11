#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long x[n];
    long y[n];

    set<pair<long,long> >sp;


    map<pair<long,long>,int>mp;

    vector<pair<long,long> >pp;

    for(int i=0;i<n;i++){
        cin >> x[i]>> y[i];
        pp.push_back(make_pair(x[i],y[i]));
        mp[pp[i]]++;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j){
                sp.insert(make_pair((x[i]-x[j]),(y[i]-y[j])));
                
            }
        }
    }
    int maxx = 0;

    sort(pp.begin(),pp.end());

    for(auto p:sp){
        int tmp = 0;
        auto mp2 = mp;
        for(int i=0;i<n-1;i++){
            int xtmp = pp[i].first + p.first;
            int ytmp = pp[i].second + p.second;
            if(mp2[make_pair(xtmp,ytmp)] >= 1){
                tmp++;
                mp2[make_pair(xtmp,ytmp)]--;
            }
        }
        maxx = max(tmp,maxx);
    }
    cout<<n-maxx<<endl;

}