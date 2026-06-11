#include<stdio.h>
main()
{
    long long m1,m2,n1,n2,i,j,a,n,M,l;

    scanf("%lld%lld%lld",&n,&M,&l);

    m1=n;
    n1=M;
    m2=M;
    n2=l;
    long long A[m1][n1],B[m2][n2],m[m1][n2];
    for(i=0; i<m1; i++)
        for(j=0; j<n2; j++)
            m[i][j]=0;
    for(i=0; i<m1; i++)
        for(j=0; j<n1; j++)
        {
            //printf("Enter %d,%d element of 1st matrix :",i+1,j+1);
            scanf("%lld",&A[i][j]);
        }
    //printf("\n");
    for(i=0; i<m2; i++)
        for(j=0; j<n2; j++)
        {
            //printf("Enter %d,%d element of 2nd matrix :",i+1,j+1);
            scanf("%lld",&B[i][j]);
        }
    for(a=0; a<m1; a++)
        for(i=0; i<n2; i++)
            for(j=0; j<n1; j++)
                m[a][i]+=A[a][j]*B[j][i];

    for(i=0; i<m1; i++)
    {
        for(j=0; j<n2; j++)
        {
            printf("%lld",m[i][j]);
            if(j!=n2-1)
                printf(" ");
        }

        printf("\n");
    }


}

