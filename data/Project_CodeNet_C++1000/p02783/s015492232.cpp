#include<stdio.h>
int main(){
 int hel, dmg;
 int atcknum,sisadarah;
 scanf("%d %d", &hel,&dmg);

atcknum = hel/dmg;
sisadarah = hel%dmg;

sisadarah > 0 ? printf("%d",atcknum +1) :printf("%d",atcknum);
  return 0;
}