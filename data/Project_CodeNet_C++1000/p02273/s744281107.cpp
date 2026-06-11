#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct vertex{
	double x;
	double y;
};

void printqueue(queue<vertex*> q){
	while (!q.empty()){
		cout << "(" << q.front()->x << "," << q.front()->y << "), ";
		q.pop();
	}
	cout << endl;
}

void printans(queue<vertex*> q){
	while (!q.empty()){
		cout << q.front()->x << " " << q.front()->y << endl;
		q.pop();
	}
}

int pow(int n, int p){
	int t = 1;
	for (int i=0; i<p; i++){
		t *= n;
	}
	return t;
}

void fractal(vertex* v1, vertex* v2, vertex* v3, vertex* left, vertex* right){
	double x1;
	double x2;
	double y1;
	double y2;
	x1 = left->x;
	y1 = left->y;
	x2 = right->x;
	y2 = right->y;

	v1->x = x1*2/3 + x2/3;
	v1->y = y1*2/3 + y2/3;

	v3->x = x1/3 + x2*2/3;
	v3->y = y1/3 + y2*2/3;

	v2->x = (x1+x2)/2 + sqrt(3)/6 * (y1-y2);
	v2->y = (y1+y2)/2 + sqrt(3)/6 * (x2-x1);
}

int main(){

	int n;
	cin >> n;

	queue<vertex*> q;
	vertex* tmp;
	tmp = new vertex;
	tmp->x = 0;
	tmp->y = 0;
	q.push(tmp);

	tmp = new vertex;
	tmp->x = 100;
	tmp->y = 0;
	q.push(tmp);

	vertex* tmp1;
	vertex* tmp2;
	vertex* v1;
	vertex* v2;
	vertex* v3;

	for (int i=0; i<n; i++){
		tmp1 = q.front();
		q.pop();
		for (int j=0; j<pow(4,i); j++){
			tmp2 = q.front();
			q.pop();
			v1 = new vertex;
			v2 = new vertex;
			v3 = new vertex;
			fractal(v1,v2,v3,tmp1,tmp2);
			q.push(tmp1);
			q.push(v1);
			q.push(v2);
			q.push(v3);
			tmp1 = tmp2;
		}
		q.push(tmp2);
	}

	printans(q);


	return 0;
}
