#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    int N,K;
    cin >> N >> K;
    
    //電球データ
    vector<int> A(N);
    rep(i,N){
        cin >> A[i];
    }
    
    
    //電球更新処理
    while(K>0){
        
        //終了判定
        bool flg = true;
        
        //累積和
        vector<int> B(N,0);
        for(int i=0; i<N; i++){
            int x = A[i];
            if(x != N) flg = false;
            
            if(i-x>=0){
                B[i-x] ++;
            }else{
                B[0]++;
            }
            if(i+x + 1 < N){
                B[i+x + 1]--;    
            }
        }
        
        for(int i=0; i<N-1; i++){
            B[i+1] += B[i];
        }
        
        //配列の更新処理
        A = B;
        K--;
        if(flg) break;
    }
    
    for(int x: A){
        cout << x << " ";
    }cout << endl;
}
