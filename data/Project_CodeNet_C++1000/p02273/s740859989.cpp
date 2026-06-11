#include <iostream>
#include <stdio.h>
#include <math.h>
#define PI 3.141592653589
using namespace std;

typedef struct{
	double x;
	double y;
}Pos;

void displayKoch(Pos, Pos, int, double rad);
void Koch(Pos*, Pos, Pos, double rad);

int main(){

	int n;
	Pos pos0, pos1;
	pos0.x = 0;
	pos0.y = 0;
	pos1.x = 100;
	pos1.y = 0;
	
	cin >> n;
	
	printf("%.8f %.8f\n",pos0.x,pos0.y);
	displayKoch(pos0, pos1, n, 0);
	printf("%.8f %.8f\n",pos1.x,pos1.y);
	
}

void displayKoch(Pos posA, Pos posB, int depth, double rad){
	
	if(depth >= 1){
		Pos positions[3];
		Koch(positions,posA,posB, rad);
		
		displayKoch(posA, positions[0], depth-1, rad);
		printf("%.8f %.8f\n",positions[0].x,positions[0].y);
		displayKoch(positions[0], positions[1], depth-1, rad+PI/3.0);
		printf("%.8f %.8f\n",positions[1].x,positions[1].y);
		displayKoch(positions[1], positions[2], depth-1, rad-PI/3.0);
		printf("%.8f %.8f\n",positions[2].x,positions[2].y);
		displayKoch(positions[2], posB, depth-1, rad);
	}
	
}

void Koch(Pos* positions, Pos posA, Pos posB, double rad){
	
	Pos s,t,u;
	double side, length;
	
	length = sqrt(pow(posB.x-posA.x,2)+pow(posB.y-posA.y,2));
	side = length / 3.0;
	
	s.x = posA.x + side * cos(rad);
	s.y = posA.y + side * sin(rad);
	t.x = s.x + side * cos(rad);
	t.y = s.y + side * sin(rad);
	u.x = s.x + side * cos(rad+PI/3.0);
	u.y = s.y + side * sin(rad+PI/3.0);
	
	positions[0] = s;
	positions[1] = u;
	positions[2] = t;
	
}