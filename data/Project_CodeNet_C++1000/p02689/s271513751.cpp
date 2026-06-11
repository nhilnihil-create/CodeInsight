#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    
    int N,M,A,B,ans=0; cin >> N >> M;
    int stage[N];
    vector<vector<int>> data(N);
    for(int i=0;i<N;i++) cin >> stage[i];
    
    for(int i=0;i<M;i++){
        cin >> A >> B;
        data.at(A-1).push_back(B-1);
        data.at(B-1).push_back(A-1);
    }
    
    for(int i=0;i<N;i++){
        int sum = 0;
        if(data.at(i).size()== 0 ){ans++; continue;};
        for(int j=0;j<data.at(i).size();j++){
            if(stage[i] > stage[data.at(i).at(j)]) sum++;
        }
        if(sum == data.at(i).size()) ans++;
    }
    cout << ans << endl;
}