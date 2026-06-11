#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int mod = (n+1) / 2;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
           int now = 0, x = i, y = j;
           while (1) {
                now++;
                if (x % 2 != y % 2)
                    break;
                x /= 2; y /= 2;
           }
           printf("%d ", now);
        }
        if(i<n)puts("");
    }
}
