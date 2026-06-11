#include <bits/stdc++.h>
using namespace std;
int main() {
    int e;
    while(scanf("%d",&e),e) {
        int ans=1<<30;
        for(int z=0;z*z*z<=e;z++) {
            for(int y=0;z*z*z+y*y<=e;y++) {
                int x=e-z*z*z-y*y;
                ans=min(ans,x+y+z);
            }
        }
        printf("%d\n",ans);
    }
}