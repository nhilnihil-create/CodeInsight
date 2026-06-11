#include <stdio.h>
#include <math.h>

struct Point{
	double x;
	double y;
};

Point roll(Point div1,Point div2){
	Point tmp_start = { div2.x-div1.x,div2.y-div1.y };
	Point tmp_end = { tmp_start.x*cos(M_PI/3) -tmp_start.y*sin(M_PI/3),
			tmp_start.x*sin(M_PI/3) + tmp_start.y*cos(M_PI/3) };
	Point ret = { tmp_end.x + div1.x,tmp_end.y + div1.y };
	return ret;
}

void outPut(Point point){
	printf("%.8f %.8f\n",point.x,point.y);
}

void calc(Point left,Point right,int count){
	Point div1 = {	(2*left.x + right.x)/3,(2*left.y + right.y)/3 };
	Point div2 = {(2*right.x + left.x)/3,(2*right.y + left.y)/3	};
	Point peek = roll(div1,div2);

	if(count > 1){
		calc(left,div1,count-1);
		calc(div1,peek,count-1);
		calc(peek,div2,count-1);
		calc(div2,right,count-1);
	}else{
		outPut(left);
		outPut(div1);
		outPut(peek);
		outPut(div2);
	}
}

int main(){
	int n;
	Point left = {0,0},right = {100,0};
	scanf("%d",&n);
	if(n == 0){
		outPut(left);
		outPut(right);
	}else{
		calc(left,right,n);
		outPut(right);
	}
}