#include <stdio.h>
#include <string.h>

int main(){
 
 int k;
 char s[102];
 
 scanf ("%d", &k);
 scanf ("%s", &s);
 int l = strlen(s);
 
 if (k < l){
 
 for (int i = 0; i < k; i++){
  printf ("%c", s[i]);
 }printf ("...");
}
 else {
  for (int j = 0; s[j] != '\0'; j++){
   printf ("%c", s[j]);
  }
 }
 
 return 0;
}