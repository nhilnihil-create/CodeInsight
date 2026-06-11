#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;
#define reverse(s) reverse(s.begin(),s.end())

int main(){
    int n;
    cin >> n;
    rep(i,n+500){
        int x = i*1.08;
        if(x==n){
            cout << i << endl;
            return 0;
        }
    }
    cout << ":(" << endl;
 
    return 0;
}