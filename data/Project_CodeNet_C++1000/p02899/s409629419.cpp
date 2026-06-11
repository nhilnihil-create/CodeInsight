#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int n;
int a[maxn];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        a[x]=i;
    }
    for(int i=1;i<=n;i++){
        printf("%d%c",a[i],i==n?'\n':' ');
    }


	return 0;
}


