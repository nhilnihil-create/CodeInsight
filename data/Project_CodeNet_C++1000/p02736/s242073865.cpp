#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1000000 + 10;
char s[N];
int a[N];
int main(){
    int n; scanf("%d",&n);
    scanf("%s",s);
    if(n==1) return 0 * printf("%s",s);
    int cnt = 0;
    for(int i=0;i<n;i++) a[i] = s[i] - '0' - 1, cnt |= (a[i]==1);
    if(cnt){
        int ans = 0;
        for(int i=0;i<n;i++) if((i&(n-1))==i) ans ^= (a[i]%2);
        printf("%d\n",ans);
    }
    else{
        int ans = 0;
        for(int i=0;i<n;i++) if((i&(n-1))==i) ans ^= (a[i]/2);
        printf("%d\n",ans*2);
    }
}
