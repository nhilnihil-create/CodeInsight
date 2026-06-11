#include <stdio.h>
int main ()
{
	int box [3][3], n, num;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			scanf ("%d", &box[i][j]);
		}
	}
	scanf ("%d", &n);
	for (int k = 0; k < n; k++){
		scanf ("%d",&num);
		
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				if(num == box[i][j]){
					box[i][j] = 0;
				}
			}
		}
	}
	
	if (box[0][0] == 0 && box[0][1] == 0 && box[0][2] == 0){
		printf ("Yes");
	} else if (box[0][0] == 0 && box[1][0] == 0 && box [2][0] == 0){
		printf ("Yes");
	}  else if (box[0][0] == 0 && box[1][1] == 0 && box [2][2] == 0){
		printf ("Yes");
	} else if (box[0][1] == 0 && box[1][1] == 0 && box [2][1] == 0){
		printf ("Yes");
	} else if (box[0][2] == 0 && box[1][2] == 0 && box [2][2] == 0){
		printf ("Yes");
	}  else if (box[1][0] == 0 && box[1][1] == 0 && box [1][2] == 0){
		printf ("Yes");
	}  else if (box[2][0] == 0 && box[2][1] == 0 && box [2][2] == 0){
		printf ("Yes");
	}  else if (box[2][0] == 0 && box[1][1] == 0 && box [0][2] == 0){
		printf ("Yes");
	}  else{
		printf ("No");
	}
	
return 0;
}