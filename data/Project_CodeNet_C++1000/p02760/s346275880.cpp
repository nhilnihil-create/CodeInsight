#include <stdio.h>
#include <stdlib.h>
 
int main()
{
  	int a[3][3];
  	int n, b,c[3][3]={0}, count;
	 
  	for(int i = 0; i < 3; i++)
  	{
	    for(int j = 0; j < 3; j++)
		{
	      scanf("%d", &a[i][j] );
	    }
  	}
  	scanf("%d",&n );
 
 	/*84 97 66
	79 89 11
	61 59 7*/
	
  	for (int k = 0; k < n; k++)
  	{
	    scanf("%d",&b);
	    for (int i = 0; i < 3; i++)
		{
	      	for (int j = 0; j < 3; j++)
		  	{
		        if (a[i][j] == b)
				{
		          c[i][j] = 1;
		        } /* 1 1 1    //a[0][0] = 84, c[0][0] = 1;
		                            0 0 0        //a[0][1] = 97, c[0][1] = 1
		                            0 0 0*/    //a[0][2] = 66, c[0][2] = 1;
		    }
	    }
  	}
	 
  	if (c[0][0] + c[1][1] + c[2][2]== 3 || c[0][2] + c[1][1] + c[2][0] == 3)
	{
	    //dalam keadaan diagonal//
	    puts("Yes");
	    return 0;
	}
	 
  	for (int i = 0; i < 3; i++)
	{
	    if (c[i][0] + c[i][1] + c[i][2] == 3 || c[0][i] + c[1][i] + c[2][i] == 3)
		{
	        //dalam keadaan sebaris || dalam keadaan sekolom//
	       	puts("Yes");
	        return 0;
	    }
    }
 	
	puts("No");
	 
	    return 0;
	}