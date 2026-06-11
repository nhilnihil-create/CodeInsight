#include <stdio.h>

int main(){

    int a,count=0,i=2;

    scanf("%d",&a);

    while(1)

    {
        while(a>i){

            if(a%i==0 && a!=2){

                count++;


            }

        i++;

        }
            if(count==0)
            {
                break;

            }

    a++;
    i=2;
    count=0;

    }
        if(count==0){

        printf("%d\n",a);


    }



return 0;

}
