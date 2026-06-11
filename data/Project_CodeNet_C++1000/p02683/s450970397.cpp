#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,M,X;
    cin >> N >> M >> X;
    vector<int> C(N);
    vector<vector<int>> A(N,vector<int>(M));
    for(int i=0; i<N; i++){
        cin >>C.at(i);
        for(int j=0; j<M; j++){
            cin >> A.at(i).at(j);
        }
    }
    int ans=10000000;
    for(int bit=0; bit<(1<<N); bit++){
        vector<int> total(M);
        int money=0;
        for(int i=0; i<N; i++){
            if(bit & (1<<i)){
                money=money+C.at(i);
                for(int j=0; j<M; j++){
                    total.at(j)+=A.at(i).at(j);
                }
            }
        }
        int cnt=0;
        for(int i=0; i<M; i++){
            if(total.at(i)<X) cnt=1;
        }
        if(cnt==0) ans=min(ans,money);
    }
    if(ans==10000000) ans=-1;
    cout << ans << endl;
    

}
