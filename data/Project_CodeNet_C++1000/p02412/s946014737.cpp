#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) range(i,0,b)
#define debug(x) cout << "debug" << x << endl;
using namespace std;

int main(){
    int a, b;
    while(cin >> a >> b,a||b){
        int ans = 0;
        range(i,1,a+1){
            range(j,i + 1,a+1){
                range(k,j + 1,a+1){
                    if(i + j + k == b) ans++;
                }
            }
        }
        cout << ans << endl;
    }
}