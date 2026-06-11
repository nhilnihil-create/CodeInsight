#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x ,n) for(int i = x; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main(){
    int N;
    cin >> N;
    
    long long A[N];
    for(int i=0;i<N;i++){
        cin >> A[i];
        if(A[i]==0){
            cout << 0;
            return 0;
        }
    }
 
    long long result = 1;
    //long long limit = pow(10.0,18.0);
    
    //bool can = true;
    for(int i=0;i<N;++i) {
            if(A[i]>1000000000000000000/result){
            result = -1;
            //can = false;
            break;
            }
        result = result *A[i];
    }
 
    
    cout << result;
}