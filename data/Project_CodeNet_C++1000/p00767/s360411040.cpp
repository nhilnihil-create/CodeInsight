#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;

int rank[150][150];

struct Info{
	int height,width,value;
};

int main(){

	Info info[11175];
	int index = 0;

	for(int height = 1; height <= 149;height++){
		for(int width = height+1;width <= 150;width++){
			info[index].height = height;
			info[index].width = width;
			info[index].value = height*height + width*width;
			index++;
		}
	}

	for(int i = 1; i <= 11174; i++){
		for(int k = 11174; k >= i; k--){
			if((info[k].value < info[k-1].value) || (info[k].value == info[k-1].value && info[k].height < info[k-1].height))swap(info[k],info[k-1]);
		}
	}

	for(int i = 0; i < 11175; i++){
		rank[info[i].height][info[i].width] = i;
	}

	int h,w,tmp;

	while(true){
		scanf("%d %d",&h,&w);
		if(h == 0 && w == 0)break;

		tmp = rank[h][w]+1;

		printf("%d %d\n",info[tmp].height,info[tmp].width);

	}

	return 0;
}