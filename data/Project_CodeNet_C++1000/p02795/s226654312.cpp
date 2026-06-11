#include<stdio.h>
#include<math.h>

int main()
{
    int H =0;
    int W =0 ;
    int N =0 ;
    double NperH=0 ;
    double NperW=0 ; 
    int result =1;
   
    scanf ("%d", &H);
    scanf ("%d", &W);
    scanf ("%d", &N);
    
    NperH= ceil(N/(double)H);
    NperW= ceil(N/(double)W);
   // printf("%.2f",ceil(NperW)); debug only
    if (NperH < NperW)
    {
        printf("%d",(int)NperH);
    }
    else
    {
        printf("%d",(int)NperW);
    }
    
    return 0;
}