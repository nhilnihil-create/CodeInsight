#include <cstdio>
using namespace std;
int main()
{
    int a,x=1,b,i=0;
    scanf("%d",&a);
    int A[a];
    while(i<a){
        scanf("%d",&A[i]);
        i++;
    }
    b=A[0];
    i=1;
    while(i<a){

        if(A[i]<b)
        {
            b=A[i];
            x++;
        }
        i++;
    }
    printf("%d\n",x);
    return 0;
}

