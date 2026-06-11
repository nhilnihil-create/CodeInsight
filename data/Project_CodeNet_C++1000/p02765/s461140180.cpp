#include <stdio.h>
 
int main()
{
    int A,B,hasil;
    scanf("%d %d", &A, &B);
    
    if (A<10){
        hasil = B + 100 * (10 - A);
    }
    else{
        hasil = B;
    }
    
	printf("%d",hasil);
 
    return 0;
}