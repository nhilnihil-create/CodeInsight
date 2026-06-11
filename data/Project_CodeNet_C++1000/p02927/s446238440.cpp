#include <bits/stdc++.h>
#include <string.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, m, n) for(int i = m; i < n; i++) 
#define mod 1000000007
#define pi 3.1415926535
typedef long long ll;

int main(){
    int M,D;
    cin>>M>>D;
    int count=0;
    FOR(i,10,D+1){
        int d1=i%10;
        int d2=i/10;
        
        FOR(j,1,M+1){
        if(d1>=2&&d2>=2&&d1*d2==j){
                count++;
            }
        }
    }
    
    cout<<count<<endl;

    return 0;
}