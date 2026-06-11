#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); ++(i))
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef pair<int, int> pii;

int main(){
    int n;
    scanf("%d", &n);
    rep(i, n){
        For(j, i+1, n){
            rep(k, 10)if(((i>>k)&1) != ((j>>k)&1)){
                printf("%d ", k+1);
                break;
            }
        }
        printf("\n");
    }
}