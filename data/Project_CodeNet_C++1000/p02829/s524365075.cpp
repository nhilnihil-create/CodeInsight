#include <bits/stdc++.h>
int main ()
{
    int A,B;
    scanf ("%d %d",&A,&B);
    if ((A==1 && B==2)||(B==1 && A==2))
    {
        printf ("3\n");
    }
    if ((A==2 && B==3)||(B==2 && A==3))
    {
        printf ("1\n");
    }
    if ((A==1 && B==3)||(B==1 && A==3))
    {
        printf ("2\n");
    }
    return 0;
}