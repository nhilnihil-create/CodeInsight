#include <stdio.h>

int main(void) {                                                                                                                                                                                  
        int n = 0;                                                                                                                                                                                
        scanf("%d", &n);                                                                                                                                                                          
        long ret = 1;                                                                                                                                                                             
        for (; n > 0; n--) {                                                                                                                                                                      
                ret *= n;                                                                                                                                                                         
        }                                                                                                                                                                                         
        printf("%ld\n", ret);                                                                                                                                                                     
                                                                                                                                                                                                  
        return 0;                                                                                                                                                                                 
}