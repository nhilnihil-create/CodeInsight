#include<iostream>
#include<deque>

using namespace std;

int main()
{
	for(;;){
		int a,b;
		int map[20][20] = {0};
		int kouji[40][2];
		int n;
		bool flg = 0;
		
		cin >> a;
		cin >> b;
		if(a == 0 && b == 0){
			break;
		}
		cin >> n;
		//a >> x, b >> y
		map[0][0] = 0;
		map[1][0] = 1;
		map[0][1] = 1;
		
		for(int i = 0; i < n; i++){
			cin >> kouji[i][0] >> kouji[i][1];
		}
		
		int i, j;
		for(i = 0; i < b; i++){
			for(j = 0; j < a; j++){
				for(int k = 0; k < n; k++){
					if(j == kouji[k][0]-1 && i == kouji[k][1]-1){
						map[i][j] = 0;
						flg = 1;
						break;
					}
				}
				if(flg != 1){
					if(i == 0 && j == 0){
						map[i][j] = 1;
					}
					else if((i == 1 && j == 0)||(i == 0 && j == 1)){
						map[i][j] = 1;
					}
					else{
						if(i == 0){
							map[i][j] = map[i][j-1];
						}
						else if(j == 0){
							map[i][j] = map[i-1][j];
						}
						else{
							
							map[i][j] = map[i-1][j] + map[i][j-1];
						}
					}
				}
				flg = 0;
			//	printf("%d\t",map[i][j]);
			//	printf("map[%d][%d] >> %d\n",i,j,map[i][j]);
			}
//			puts("");
		}
		printf("%d\n",map[b-1][a-1]);
	}
}