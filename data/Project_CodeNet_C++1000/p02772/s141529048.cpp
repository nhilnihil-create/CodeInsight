#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

int main(){
    int n;  cin >> n;

    bool ans(true);
    rep(i,n){
        int x;  cin >> x;

        if(x%2==0){
            if (!(x % 3 == 0 || x % 5 == 0))
            {
                ans = false;
            }
        }
    }

    if(ans){
        puts("APPROVED");
    }else{
        puts("DENIED");
    }

    return 0;
}