#include<iostream>
using namespace std;

int Harmony(int *A, int *B)
{
    if(*A>*B)
    {
        for(int i=(*B);i<(*A);i++)
        {
            if((i-(*B))==((*A)-i))
                return i;
        }
        goto label;
    }

    else if(*A<*B)
    {
        for(int i=(*A);i<(*B);i++)
        {
            if((i-(*A))==((*B)-i))
                return i;
        }
        goto label;
    }

    else
    {   label:
        return 0;
    }


}

int main()
{

    int A,B;
    int K;
    scanf("%d %d",&A,&B);
    K=Harmony(&A,&B);
    if(K!=0)
        printf("%d",K);
    else
        printf("IMPOSSIBLE");
    return 0;
}
