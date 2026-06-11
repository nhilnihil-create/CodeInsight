/***********************************************/
/* 2014.06.28 S_Nakka                          */
/*              0000：九九計算                 */
/* take1:新規作成                              */
/***********************************************/

#include<stdio.h>

int main(){

	int multiply1;
	int multiply2;

	for(multiply1 = 1; multiply1 <= 9; multiply1++)
	{
		for(multiply2 = 1; multiply2 <= 9; multiply2++)
		{
			printf("%dx%d=%d\n", multiply1, multiply2, 
				multiply1*multiply2);
		}
	}
    return 0;
}