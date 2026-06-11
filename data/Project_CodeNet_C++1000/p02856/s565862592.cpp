#include <iostream>
using namespace std;
const int N=200000+10;
typedef long long LL;
int n,d; LL x; 
int main(){
    scanf("%d",&n);
    LL s=0,s1 = 0;
    for(int i=1;i<=n;i++){
        scanf("%d%lld",&d,&x);
        s += d * x; s1 += x;
    }
    LL ans = (s - 1) / 9 + s1 - 1;
    cout << ans << endl;
}