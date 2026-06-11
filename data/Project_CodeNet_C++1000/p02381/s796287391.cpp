#include <stdio.h>
#include <math.h>
int main(){
  for(;;){
    int i;
    float n;
    float S[1000],SUM=0;
    float m,bunsan,bbunsan,SSUM=0;
    scanf("%f",&n);
    if(n==0){
      return 0;
    }
    for(i=0;i<n;i++){
      scanf("%f",&S[i]);
      SUM+=S[i];
    }
    m=SUM/n;
    for(i=0;i<n;i++){
      SSUM+=(S[i]-m)*(S[i]-m);
    }
    bbunsan=SSUM/n;
    bunsan=sqrt(bbunsan);
    printf("%f\n",bunsan);
  }
}