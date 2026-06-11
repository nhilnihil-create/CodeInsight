#include <bits/stdc++.h>

using namespace std;

const int maxn = 65;
bool ch[maxn];
long long mask[maxn];
long long a[100005], all;
void Insert(long long t){
    for(int i=60;i>=0;i--){
        if(ch[i]) continue;
        if((t>>i)&1){
            if(mask[i]==0){
                mask[i] = t;
                return;
            }
            t^=mask[i];
        }
    }

}


int main()
{

    int n;
    scanf("%d", &n);
    all = 0;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld", &a[i]);
        all^=a[i];
    }
    for(int i=0;i<=60;i++){
        if((all>>i)&1) ch[i] = 1;
        else ch[i] = 0;
    }
    for(int i=0; i<=60; i++){
        if(ch[i]){
            for(int j=1;j<=n;j++){
                if((a[j]>>i)&1){
                    a[j]^=(1LL<<i);
                }
            }
        }
    }
    for(int i=1; i<=n; i++){
        Insert(a[i]);
    }
    long long ans = 0;
    for (int i = 60; i >= 0; i--) {
		if (!mask[i]) continue;

		if (ans & (1LL<<i)) continue;

		ans ^= mask[i];
	}
    printf("%lld\n", ans + (all ^ ans));

    return 0;
}

