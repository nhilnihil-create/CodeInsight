#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+100;
char s[N];
int main()
{
    int n, A, B, C, D;
    scanf("%d%d%d%d%d",&n, &A, &B, &C, &D);
    scanf("%s", s+1);
    if( C == D )
        printf("No\n");
	else if(C < D)
	{
        int flag = 1 ;
        for(int i = A; i < C; i++)
		{
            if(s[i] == '#' && s[i+1] == '#')
			{
                flag = 0;
                break ;
            }
        }
        for(int i = B; i < D; i++)
		{
            if(s[i] == '#' && s[i+1] == '#')
			{
                flag = 0;
                break ;
            }
        }
        if(flag)
            printf("Yes\n");
		else
           printf("No\n");
    }
	else
	{
        int flag = 1 ;
        for(int i = B; i < D; i++)
		{
            if ( s[i] == '#' && s[i+1] == '#' )
			{
                flag = 0;
                break;
            }
        }
        for(int i = A; i < C; i++)
		{
            if((s[i] == '#' && s[i+1] == '#') || (s[i] == '#' && i+1 == D ) || (s[i+1] == '#' && i == D ))
			{
                flag = 0;
                break;
            }
        }
         
        int f = 0;
        for(int i = B; i <= D-1; i++)
		{
            if(s[i-1] == '.' && s[i] == '.' && s[i+1] == '.' )
			{
                f = 1;
                break;
            }
        }
        if(flag || f)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0 ;
}