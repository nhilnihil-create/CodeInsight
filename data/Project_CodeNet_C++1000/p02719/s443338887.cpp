#include<bits/stdc++.h>
using namespace  std;
int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
    long long n,k;
    while(~scanf("%lld %lld",&n,&k))
    {
        n%=k;
        if(k==1)
        {
            printf("0\n");
       }
        else
        {
            long long minn=n;
            while(1) {
                long long flag = abs(minn - k);
                if (flag < minn) {
                    minn = flag;
                } else {
                    break;
                }
            }

            printf("%lld\n",minn);
        }

    }
    return 0;
}