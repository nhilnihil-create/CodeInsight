#include <stdio.h>
#include <math.h>
#include <algorithm>

int num_of_point[7] = {2,5,17,65,257,1025,4097},n,points_index = 0;

struct Point{
	double x;
	double y;
};

Point points[4097];

Point roll(Point div1,Point div2){
	Point tmp_start = { div2.x-div1.x,div2.y-div1.y };
	Point tmp_end = { tmp_start.x*cos(M_PI/3) -tmp_start.y*sin(M_PI/3),
			tmp_start.x*sin(M_PI/3) + tmp_start.y*cos(M_PI/3) };
	Point ret = { tmp_end.x + div1.x,tmp_end.y + div1.y };
	return ret;
}

void calc(Point left,Point right,int count){
	Point div1 = {	(2*left.x + right.x)/3,(2*left.y + right.y)/3 };
	Point div2 = {(2*right.x + left.x)/3,(2*right.y + left.y)/3	};
	Point peek = roll(div1,div2);

	points[points_index++] = div1;
	points[points_index++] = div2;
	points[points_index++] = peek;

	if(count > 1){
		calc(left,div1,count-1);
		calc(div1,peek,count-1);
		calc(peek,div2,count-1);
		calc(div2,right,count-1);
	}else{
		printf("%.8f %.8f\n",left.x,left.y);
		printf("%.8f %.8f\n",div1.x,div1.y);
		printf("%.8f %.8f\n",peek.x,peek.y);
		printf("%.8f %.8f\n",div2.x,div2.y);
	}
}

int main(){
	Point left = {0,0},right = {100,0};
	points[points_index++] = left;
	points[points_index++] = right;
	scanf("%d",&n);

	if(n == 0){
		printf("%.8f %.8f\n",left.x,left.y);
		printf("%.8f %.8f\n",right.x,right.y);
	}else{
		calc(left,right,n);
		printf("%.8f %.8f\n",right.x,right.y);
	}
}