// ConsoleApplication7.cpp : ??????????????? ??¢????????±????????§????????¨????????? ?????????????????????????????????
//

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct {
	int top;
	int front;
	int right; 
	int left; 
	int back;
	int bottom;	
} dice_type;

void move(char direction, dice_type* p_dt);

int main(int argc, char* argv[])
{
	int i;
	dice_type dice;
	char movement[101];
	
	cin >> dice.top;
	cin >> dice.front;
	cin >> dice.right;
	cin >> dice.left;
	cin >> dice.back;
	cin >> dice.bottom;
	cin >> movement;

	for (i = 0; movement[i]; i++) {
		move(movement[i], &dice);
	}
	cout << dice.top << endl;

	return 0;
}

void move(char direction, dice_type* p_dt) {
	dice_type d = *p_dt;

	switch (direction) {
	case 'S':
		p_dt->top = d.back;
		p_dt->front = d.top; 
		p_dt->back = d.bottom;
		p_dt->bottom = d.front; 
		break;
	case 'N':
		p_dt->top = d.front;
		p_dt->front = d.bottom; 
		p_dt->back = d.top;
		p_dt->bottom = d.back;
		break;
	case 'E':
		p_dt->top = d.left;
		p_dt->right = d.top; 
		p_dt->left = d.bottom; 
		p_dt->bottom = d.right;
		break;
	case 'W':
		p_dt->top = d.right;
		p_dt->right = d.bottom; 
		p_dt->left = d.top; 
		p_dt->bottom = d.left;
		break;
	}
}