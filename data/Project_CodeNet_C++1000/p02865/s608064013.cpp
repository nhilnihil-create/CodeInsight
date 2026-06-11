#include <bits/stdc++.h>
 
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
    int n; cin >> n;
    int ans = 0;
    if(n%2 == 0){
        ans = n/2 - 1;
    }else{
        ans = n/2;
    }
    cout << ans << endl;
    
    

}
