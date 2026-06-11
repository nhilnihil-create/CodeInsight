#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
struct c{
    int x,y;
} z[110];
bool comp(c a,c b){
    return atan2(a.y,a.x)<atan2(b.y,b.x);
}
signed main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>z[i].x>>z[i].y;
    }
    sort(z,z+n,comp);
    double ans=0;
    for(int i=0;i<n;i++){
        int j=i;
        int x=0,y=0;
        do{
            x+=z[j].x;
            y+=z[j].y;
            ans=max(ans,(double)sqrt(x*x+y*y));
            j++;
            j%=n;
        }while(j!=i);
    }
    printf("%.20llf",ans);
    return 0;
}