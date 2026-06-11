#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i )

using namespace std;
typedef long long ll;

bool is_Prime (int n){
    bool flag = true;
    if(n==1){
        return false;
    }
    for(ll i=2; i*i<=n; i++){
        if(n%i==0){
	    flag = false;
	    break;
        }
    }
    return flag;
}

int main(){
    int X; cin >> X;
    int flag = false;
    int ans;
    for(int i = X;i < 200000; i++){
        flag = is_Prime(i);
        if (flag == true){
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}