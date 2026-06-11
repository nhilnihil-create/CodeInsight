#include<bits/stdc++.h>
using namespace std;

int main(){
    int mod=1000000007;
    int n,m;
    char s[30005];
    int d[10][2];
    set<int> ans;
    for (int i=0;i<10;i++) {
        d[i][0]=30005;
        d[i][1]=-1;
    }
    scanf("%d",&n);
    scanf("%s",s);
    for (int i=0;i<n;i++) {
        int p=s[i]-'0';
        if (d[p][0]==30005) {
            d[p][0]=i;
            d[p][1]=i;
        } else {
            d[p][1]=i;
        }
    }
    for (int i=1;i<n-1;i++) {
        for (int j=0;j<10;j++) {
            if (d[j][0]<i) {
                for (int k=0;k<10;k++) {
                    if (d[k][1]>i) ans.insert(j*100+(s[i]-'0')*10+k);
                }
            }
        }
    }
    printf("%ld\n",ans.size());
    return 0;
}
