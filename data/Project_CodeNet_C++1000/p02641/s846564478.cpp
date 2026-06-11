#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

#define FOR(i,N) for(int i=0;i<N;i++)

int main(){
    long long N,K,X,X1,X2,ans=0,keep1,keep2;
    cin >> X >> N;
    vector<long>p(N);
    FOR(i,N)cin >> p[i];
    if(count(p.begin(),p.end(),X) == 0){
        ans = X;
    }else{
        X1=X;
        X2=X;
        while(true){
            X1--;
            X2++;
            if(count(p.begin(),p.end(),X1) == 0){
                ans = X1;
                break;
            }
            if(count(p.begin(),p.end(),X2) == 0){
                ans = X2;
                break;
            }
        }
    }
    cout << ans << endl;
}