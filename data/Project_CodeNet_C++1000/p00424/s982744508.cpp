#include <stdio.h>   
char c[256];   
void clear() {  
 int i; for (i = 0; i < 256; i++) c[i] = 0; }  
 int main() {  
 int n;  
 char f, t;  
 while (1) {    
 scanf("%d\n", &n);   
  if (!n) break;       
    clear();   
  while (n--) {    
   scanf("%c %c\n", &f, &t);    
   c[f] = t;    
 }        
   scanf("%d\n", &n);   
  while (n--) {    
   scanf("%c\n", &f);   
    if (c[f]) printf("%c", c[f]);    
   else printf("%c", f);  
   }   
  printf("\n");  
 }  
 return 0; 
} 