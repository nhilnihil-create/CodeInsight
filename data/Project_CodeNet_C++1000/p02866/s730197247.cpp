#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main() {
    int N;
    cin>>N;
    vector<int> D;
    map<int, int> Dmap;
    int tmp;
    long ans;
    long mod = 998244353;
    for(int i=0;i<N;++i){
        cin>>tmp;
        D.push_back(tmp);
    }
    if(D[0] != 0){
        ans = 0;
    }
    else {
        ans = 1;
    }
    Dmap[0]++;
    sort(D.begin(), D.end());
    for(int i=1;i<D.size();++i){
        if(D[i] == 0){
            ans = 0;
        }
        Dmap[D[i]]++;
    }
    /**
    for(int i=0;i<D[D.size()-1];++i){
        cout<<i<<" "<<Dmap[i]<<endl;
    }
    **/
    for(int i=0;i<D[D.size()-1];++i){
        for(int j=0;j<Dmap[i+1];++j){
            ans *= Dmap[i];
            ans %= mod;
        }
    }
    cout<<ans<<endl;
}
