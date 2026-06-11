#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int main(){
    int N; cin >> N;
    int cur = -1, tar = 0, cnt = 0,ans = 0;
    for(int i=0;i<N;i++){
        cin >> tar;
        if(cur>=tar){
            cnt++;
            ans = max(ans,cnt);
        }else cnt=0;
        cur = tar;
    }
    cout << ans << endl;
}