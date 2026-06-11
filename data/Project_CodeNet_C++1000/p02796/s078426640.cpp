#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    vector<long long> X(N),L(N);
    vector<pair<long long,long long>> Z(N);
    for(int i = 0; i < N; i++){
        cin >> X[i] >> L[i];
        Z[i] = {X[i] - L[i],X[i] + L[i]};
    }
    sort(Z.begin(),Z.end(),[](pair<long long,long long> a,pair<long long,long long> b){
        return a.second < b.second; 
    });
    
    long long index = Z[0].second;
    long long ans = 1;
    for(int i = 1; i < N; i++){
        if(index <= Z[i].first){
            index = Z[i].second;
            ans++;
        }
    }
    cout << ans << endl;
    
}


