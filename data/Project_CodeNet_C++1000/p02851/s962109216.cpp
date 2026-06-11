#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    long N, K;
    cin >> N >> K;
    long A[N+1];
    long S[N+1];
    S[0]=0;
    for(long i=1; i<N+1; i++){
        cin >> A[i];
        S[i]=S[i-1]+A[i];
    }

    long ans=0;
    unordered_map<long, long> mp;
    for(long j=1; j<=N; j++ ){
        if( j-K >= 0 ){
            mp[ (S[j-K]-(j-K))%K ] -= 1;
            //cout << "delete j K i " << j << " " << K << " " << j-K << endl; 
        }
        if( j-1 >= 0 ){
            mp[ (S[j-1]-(j-1))%K ] += 1;
            //cout << "add j 1 i " << j << " " << 1 << " " << j-1 << endl; 
        }
        ans += mp[ (S[j]-j)%K ];
        //cout << "j ans " << j << " " << ans << endl;
    }
    
    cout << ans << endl;

    return 0;
}