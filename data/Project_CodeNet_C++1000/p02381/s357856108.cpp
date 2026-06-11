#include <cstdio>
#include <cmath>
int s[1000];

int main(){
    int n;
    double m,sum,var,dev;
    while(1){
        sum = 0.0,var = 0.0,m = 0.0,dev = 0.0;
        scanf("%d",&n);
        if(n == 0)
            break;
        for(int i = 0;i < n;i++){
            scanf("%d",&s[i]);
            sum += s[i];
        }  
        m = sum / n;
        for(int i = 0;i < n;i++)
            var += (s[i] - m) * (s[i] - m);
        dev = sqrt(var/n);
        printf("%.8lf\n",dev);
    }

    return 0;
}
