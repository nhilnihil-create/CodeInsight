#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<long long, long long>> p(n);
    for(int i=0;i<n;++i){
        long long x,l;
        cin>>x>>l;
        p[i]=make_pair(x+l,x-l);
    }

    sort(p.begin(),p.end());

    int ans=0;
    int crt=-1e9+1;
    for(int i=0;i<n;++i){
        if(p[i].second>=crt){
            crt=p[i].first;
            ++ans;
        }
    }

    cout<<ans<<endl;
} 