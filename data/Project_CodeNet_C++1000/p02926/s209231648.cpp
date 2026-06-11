#include <bits/stdc++.h>
using namespace std;
struct engine{
    int x,y;
    long double angle;
    engine(int _x, int _y){
        x = _x, y = _y;
        angle = atan((long double)y/x);
        if (x < 0){
            angle += 3.1415926535897932384626;
        }
    }
}*a[105];
long long calc(int x, int y){
    return ((long long)x)*x + ((long long)y)*y;

}
int main(){
    int n;
    scanf("%d",&n);
    int sumx = 0, sumy = 0;
    for (int i = 0; i < n; i++){
        int x,y;
        scanf("%d%d",&x,&y);
        a[i] = new engine(x,y);
        sumx += x; sumy += y;
    }
    sort(&a[0],&a[n],[](engine *a, engine *b){
        return a->angle < b->angle;
    });
    int px[n+1], py[n+1];
    px[0] = 0, py[0] = 0;
    long long ans = 0;
    for (int i = 1; i <= n; i++){
        //printf("%d %d\n",a[i]->x,a[i]->y);
        px[i] = px[i-1] + a[i-1]->x;
        py[i] = py[i-1] + a[i-1]->y;
        for (int j = 0; j < i; j++){
            int xx = px[i] - px[j];
            int yy = py[i] - py[j];
            //printf("%d %d %lld\n",xx,yy,calc(xx,yy));
            ans = max(ans,max(calc(xx,yy),calc(sumx-xx,sumy-yy)));
        }
    }
    //printf("%lld\n",ans);
    printf("%.10f",pow(ans,0.5));


}
