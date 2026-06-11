#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<queue>
#include<vector>
#include<map>



using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

int n,m;
int s[10],c[10];
int flag=true;
int ans;
string t;

int main(){
    cin >> n >> m;
    rep(i,m){
        cin >> s[i] >> c[i];
    }
    int idx = (int)(pow(10,n-1)+0.5);
    int sidx;
    if(idx == 1){
        sidx = 0;
    }
    else sidx = idx;
    // cout << idx << endl;
    for(int i=sidx;i<idx*10;i++){
        t = to_string(i);
        flag = true;
        rep(j,m){
            int tint = t[s[j]-1] - '0';
            // cout << tint << " " << c[j] << endl;
            if( tint != c[j]) flag = false;
        }
        if (flag) {
            ans = i;
            break;
        }
    }

    if(flag) cout << ans;
    else cout << -1 << endl;
    return 0;
}