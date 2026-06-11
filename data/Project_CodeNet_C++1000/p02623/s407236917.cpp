#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n , m ;
    long long k;
    cin >> n >> m >> k;
    vector<long long> a(n + 1) , b(m + 1)  ;
    for( int i  = 1 ; i<=n ; i++){
        cin>>a[i];
    }
    for(int i = 1 ; i<= m ;i++){
        cin >> b[i];
    }

    vector< long long > prfxA( n+1 , 0 ) , prfxB(m+1,0);
    for(int i = 1; i <=n ;i++){
        prfxA[i] = prfxA[i-1] + a[i];
    }
    for(int i = 1 ; i<= m ; i++){
        prfxB[i] = prfxB[i-1] + b[i];
    }

    int ans = 0;
    for(int i = 0 , j = m; i<=n && prfxA[i] <= k ; i++ ){
        while(prfxA[i] + prfxB[j] > k){
            j--;
        }
        
        ans = max(ans ,  i + j );
    }

    cout <<  ans;
}