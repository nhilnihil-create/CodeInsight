#include <iostream>
#include <stdlib.h>

using namespace std;

int d[8][2] = {
	{-1, -1},
	{0, -1},
	{1, -1},
	{-1, 0},
	{1, 0},
	{-1, 1},
	{0, 1},
	{1, 1}
};

void func(int **a, int s, int t, int i, int j)
{
	if(a[i][j] == 0){
		return ;
	}
	a[i][j] = 0;
	
	for(int k = 0; k < 8; k++){
		if((i+d[k][0] >= 0 && i+d[k][0] < t) && (j+d[k][1] >= 0 && j+d[k][1] < s)){
			func(a, s, t, i+d[k][0], j+d[k][1]);
		}
	}
	
	return ;
}

int main(int argc, char **argv)
{
	int s, t, **a, c, t2, s2;
	
	while(1){
		cin >> s >> t;
		if(s == 0 && t == 0){
			break;
		} else if(s == 1 || t == 1){
			t2 = t+1;
			s2 = s+1;
		} else {
			t2 = t;
			s2 = s;
		}
		a = (int **)calloc(t2, sizeof(int));
		for(int i = 0; i < t; i++){
			a[i] = (int *)calloc(s2, sizeof(int));
			for(int j = 0; j < s; j++){
				cin >> c;
				a[i][j] = c;
			}
		}
		c = 0;
		
		for(int i = 0; i < t; i++){
			for(int j = 0; j < s; j++){
				if(a[i][j] == 1){
					c++;
					func(a, s, t, i, j);
				}
			}
		}
		cout << c << endl;
		
		for(int i = 0; i < t2; i++){
			free(a[i]);
		}
		free(a);
	}
	
	return 0;
}