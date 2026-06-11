#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
# define mod 1000000007
# define INF (1 << 29)
# define MAX_N 1000010
/* ちゃんと考えてわかって実装 */

int main(void){
    int n, k, c;
    cin >> n >> k >> c;
    string s;
    cin >> s;

    vector<int> L(k+1), R(k+2);
    L[0] = -INF;
    R[k+1] = INF;

    int jb = 0;
    // 最速で働いた場合
    for(int i=0; i<n; i++){
        if(s[i] == 'o' && L[jb] + c < i){
            jb++;
            L[jb] = i;
        }
        if(jb >= k) break; 
    }

    // もっとも遅い場合
    jb = k+1;
    for(int i=n-1; i>=0; i--){
        if(s[i] == 'o' && R[jb] - i > c){
            jb--;
            R[jb] = i;
        }
        if(jb <= 1) break;
    }

    for(int i=1; i<=k; i++){
        if(L[i] == R[i]){
            cout << L[i]+1 << endl;
        }
    }
    return 0;
}