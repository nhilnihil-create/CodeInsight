#include <stdio.h>
#include <string.h>
#include <math.h>
int main ()
{
    int n;
    scanf ("%d", &n);
    int a[n], a1[n];
    for (int i=0;i<n;i++) {
        scanf ("%d",&a[i]);
        a1[a[i]-1]=i+1;
    }
    for (int j=0;j<n;j++) {
        printf ("%d ", a1[j]);
    }
}
