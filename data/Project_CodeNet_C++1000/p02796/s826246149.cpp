#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    vector<pair<long long,long long>> index(N);
    for(int i = 0; i < N;i++){
        long long X,L; cin >> X >> L;
        index[i] = {X - L,X + L};
    }
    sort(index.begin(),index.end(),[](pair<long long,long long> &a,pair<long long,long long> &b){
        return a.second < b.second;
    });
    
    long long key = index[0].second;
    int ans = 1;
    for(int i = 1; i < N; i++){
        //cout << key <<" "<< index[i].first << " "<< index[i].second<< endl;
        if(key <= index[i].first){
            ans++;
            key = index[i].second;
        }
    }
    cout << ans << endl;
    
    
    
    
}


