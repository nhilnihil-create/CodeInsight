#include<cstdio>
int main(){
	int SpreadSheet[100][100];
	int SumOfRow[100];
	int SumOfColumn[100];
	int row,column;
	scanf("%d %d",&row,&column);
	for(int i=0;i<row;i++){
		SumOfRow[i] = 0;
		for(int j=0;j<column;j++){
			scanf("%d",&SpreadSheet[i][j]);
			printf("%d ",SpreadSheet[i][j]);
			SumOfRow[i] += SpreadSheet[i][j];
		}
		printf("%d\n",SumOfRow[i]);
	}
	for(int j=0;j<column;j++){
		SumOfColumn[j] = 0;
		for(int i=0;i<row;i++){
			SumOfColumn[j] += SpreadSheet[i][j];
		}
	}
	int SumOfAll = 0;
	for(int i=0;i<row;i++){
		SumOfAll += SumOfRow[i];
	}
	for(int j=0;j<column;j++){
		printf("%d ",SumOfColumn[j]);
	}
	printf("%d\n",SumOfAll);
	return 0;
}