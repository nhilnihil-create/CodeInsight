#include <bits/stdc++.h>
using namespace std;

long long N;

long long lr(long long x, long long y, long long xx, long long yy){
    return x*yy-y*xx;
}

struct data{
    long long x, y;
}arr[20000004];
struct dat{
    long long x, y, num;

    bool operator<(const dat&r)const{
        return lr(x, y, r.x, r.y)>0 || (lr(x, y, r.x, r.y) == 0 && x*x+y*y<r.x*r.x+r.y+r.y);
    }
}startFar[20000004];
long long stk[20000004];
long long top;

int main(){
    long long M; scanf("%lld", &M);
    N = 1; arr[1].x = 0, arr[1].y = 0;
    while(M--){
        long long a, b; scanf("%lld %lld", &a, &b);
        if(!a && !b) continue;
        for(long long i=0;i<N;i++) arr[i + N].x = arr[i].x + a, arr[i + N].y = arr[i].y + b;
        N *= 2;
        if(N > 2){
            long long minNum = 0;
            for(long long i=1;i<N;i++){
                if(arr[i].y<arr[minNum].y||(arr[i].y==arr[minNum].y&&arr[i].x<arr[minNum].x)) minNum = i;
            }
            swap(arr[minNum], arr[0]);
            for(long long i=1;i<N;i++){
                startFar[i].num = i;
                startFar[i].x = arr[i].x-arr[0].x;
                startFar[i].y = arr[i].y-arr[0].y;
            }
            sort(startFar+1, startFar+N);
            stk[0] = 0;
            top = 1;
            for(long long i=1;i<N;i++){
                if(startFar[i].x == startFar[i - 1].x && startFar[i].y == startFar[i - 1].y){
                    continue;
                }
                long long cando = 1;
                while(top > 1){
                    long long gap = lr(arr[stk[top-1]].x-arr[stk[top-2]].x, arr[stk[top-1]].y-arr[stk[top-2]].y, arr[startFar[i].num].x-arr[stk[top-2]].x, arr[startFar[i].num].y-arr[stk[top-2]].y);
                    if(gap < 0){
                                    --top;
                                   }
                    else if(gap == 0 && (arr[stk[top-1]].x-arr[stk[top-2]].x)*(arr[stk[top-1]].x-arr[stk[top-2]].x)+
                                   (arr[stk[top-1]].y-arr[stk[top-2]].y)*(arr[stk[top-1]].y-arr[stk[top-2]].y)<
                                   (arr[startFar[i].num].x-arr[stk[top-2]].x)*(arr[startFar[i].num].x-arr[stk[top-2]].x)+
                                   (arr[startFar[i].num].y-arr[stk[top-2]].y)*(arr[startFar[i].num].y-arr[stk[top-2]].y)){
                                    --top;
                                   }
                    else{
                        if(!gap) cando = 0;
                        break;
                    }
                }
                if(cando) stk[top++] = startFar[i].num;
            }
            sort(stk, stk + top);
            for(long long i=0;i<top;++i){
                arr[i] = arr[stk[i]];
            }
            N = top;
        }
    }
    double ans = 0;
    for(long long i=0;i<N;++i){
        ans = max(ans, sqrt(arr[i].x*arr[i].x+arr[i].y*arr[i].y));
    }
    printf("%.12lf", ans);
    return 0;
}
