#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,P;
    long long ans=0;
    char c;
    cin >> N >> P;
    int S[N];
    for(int i=N-1; i>=0; i--){
        cin >> c;
        S[i]=(c-'0');
    }
    if(P==2 || P==5){
        for(int i=0; i<N; i++){
            if(S[i]%P==0){
                ans+=N-i;
            }
        }
    }else{
        long long R[P]={0};
        R[0]=1;
        int base=1;
        int sModP=0;
        for(int i=0; i<N; i++){
            sModP+=(base*S[i]);
            sModP%=P;
            R[sModP]++;
            base*=10;
            base%=P;
        }
        for(int i=0; i<P; i++){
            if(R[i]>1) ans+=(R[i]*(R[i]-1))/2;
        }
    }
    cout << ans;
    return 0;
}
