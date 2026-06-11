#include<bits/stdc++.h>
using namespace std;

#define sc1(a)  scanf("%d",&a)

int main(){
    int mod=1000000007;
    int n,ans;
    sc1(n);
    for (int i=1;i<10;i++)  for (int j=i;j<10;j++) {
        if (i*j==n) {
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}
