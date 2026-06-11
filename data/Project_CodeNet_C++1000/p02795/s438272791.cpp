#include<stdio.h>
int main()
{
    int baris,kolom,n,i= 0;
    int tamp,count =0;
    scanf("%d %d %d",&baris, &kolom, &n);
    if(baris>kolom)
	{
        tamp=baris;
    }else
	{
        tamp=kolom;
    }
    for(i=0;i<n;i=i+tamp)
	{
        count++;
    }
    printf("%d",count);
    
    
    return 0;
}