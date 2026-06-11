#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+5;
const int mod=1e9+7;
int n;
vector<int>a,b;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%d%d",&x,&y);

        a.push_back(x+y);
        b.push_back(x-y);
    }

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    printf("%d\n",max(a[n-1]-a[0],b[n-1]-b[0]));

    return 0;
}
