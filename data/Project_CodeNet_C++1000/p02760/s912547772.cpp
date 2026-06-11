#include <stdio.h>
int main(){
    int array[3][3];
    int n; 
    int add;
    int check[3][3]={0};
    int count;
    for(int i = 0; i < 3; i++)
	{ 
        for(int j = 0; j < 3; j++)
		{ 
            scanf("%d", &array[i][j]);
        } 
    }
    scanf("%d",&n);
    for(int k = 0; k < n; k++)
	{
        scanf("%d",&add);
        for(int i = 0; i < 3; i++)
		{
            for(int j = 0; j < 3; j++)
			{
                if(array[i][j] == add)
                {
                    check[i][j] = 1;
                }
            }
        }
    }
    if(check[0][0] + check[1][1] + check[2][2] == 3 || check[0][2] + check[1][1] + check[2][0] == 3)
	{
        printf("Yes\n");
        return 0;
    }
    for(int i = 0; i < 3; i++){
        if(check[i][0] + check[i][1] + check[i][2] == 3 || check[0][i] + check[1][i] + check[2][i] == 3)
		{
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}