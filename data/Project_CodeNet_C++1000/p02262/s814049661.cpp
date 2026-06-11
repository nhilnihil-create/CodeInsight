#include <stdio.h>
int main(void){
    int n;
    int gap_n;
    int gap;
    int cnt;
    scanf("%d", &n);
    
    int gaps[40];
    int n_ = n;
    gap_n = 0;
    while (n_ > 3) {
        gaps[gap_n] = n_ - 2;
        n_ /= 2;
        gap_n++;
    }
    gaps[gap_n++] = 1;
    
    int arr[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", gap_n);
    for (int g=0; g<gap_n; g++) {
        if (g!=0) printf(" ");
        printf("%d", gaps[g]);
    }
    printf("\n");
        
    cnt = 0;
    for (int g=0; g<gap_n;g++) {
        gap = gaps[g];
        for (int i=0; i<n; i++) {
            int j=i;
            int value = arr[i];
            while ((j>=gap) && (arr[j-gap]>value)) {
                arr[j] = arr[j-gap];
                j -= gap;
                cnt++;
            }
            arr[j] = value;
        }
    }
    
    printf("%d\n", cnt);
    
    for (int i=0; i<n; i++) {
        if (i!=0) printf("\n");
        printf("%d", arr[i]);
    }
}

