#include <stdio.h>
#include <string.h>

#define ll long long int
#define fl(i,a,n) for(int i = a; i < (n); i++)
#define fls(i,a,s) for(int i = a; s[i] != '\0'; i++)

int main() {
    int n;
    scanf("%d", &n);
    int arr[n], ctr = 0;
    fl(i,0,n){
        scanf("%d", &arr[i]);
    }
    fl(i,0,n-2){
        fl(j,i+1,n-1){
            fl(k,j+1,n){
                if((arr[i] + arr[j] > arr[k] && arr[j] + arr[k] > arr[i] && arr[i] + arr[k] > arr[j]) && (arr[i] != arr[j] && arr[k] != arr[i] && arr[j] != arr[k])){
                    ctr++;
                }
            }
        }
    }
    printf("%d\n", ctr);
    
    return 0;
}
