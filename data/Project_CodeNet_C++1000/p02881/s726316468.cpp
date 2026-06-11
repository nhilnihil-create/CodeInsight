#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<queue>
#include<vector>
#include<map>



using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep(i,n) for(int i=0;i<(n);i++)

long long int n;
long long int ans=10000000000000;
int main(){
    cin >> n;
    long long int i,j;
    for (int i=1;(long long int)i*i<=n;i++){
        if(n%i == 0){
            ans = min(ans , i+n/i-2);
        }
    }
    cout << ans << endl;

return 0;
}