#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)


int main(){
    int N,M,X;
    cin >> N >> M >> X;

    if(N==0||M==0||X==0){
        cout << -1 << endl;
        return 0;
    }
    vector<int> C(N);
    vector<vector<int>> A(N,vector<int>(M));
    long money=0;
    long result=1000000000;
    vector<int> sum(M);

    rep(i,N){
        cin >> C.at(i);
        rep(j,M){
            cin >> A.at(i).at(j);
        }
    }

    for (int bit=0; bit<(1<<N);bit++) { // 0000...00 ~ 1000...00(2^N個)
        money=0;
        rep(i,M) sum.at(i)=0;

        for(int i=0;i<N;i++){ // シフトを右にずらして判定
            if((bit >> i) & 1){
                money += C.at(i);
        //        cout << money << endl;
                for(int k=0;k<M;k++){
                    sum.at(k) += A.at(i).at(k);
                  //  cout << sum.at(k) << endl;
                }
            }
        }

        int flg=0;
        rep(i,M){
            if(sum.at(i)<X) flg=1;
        }
        if(flg!=0) continue;
        

        result = min(result,money);
  //      cout << result << endl;

    }
    if(result == 1000000000) cout << -1 << endl;
    else cout << result << endl;


}