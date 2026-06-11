#include <cstdio>
#include <cstring>

int main(void)
{
    int n;
    int num[5001];
    int sum;
    int max;
    
    while (scanf("%d", &n)){
        if (n == 0) break;
        
        memset(num, 0, 5001);
        for (int i = 0; i < n; i++){
            scanf("%d", &num[i]);
        }
        max = num[0];
        
        for (int i = 0; i < n; i++){
            sum = 0;
            for (int j = i; j < n; j++){
                sum += num[j];
                if (max < sum) max = sum;
            }
        }
        
        printf("%d\n", max);
    }
}