#include<iostream>
using namespace std;

struct Dice {
	int top;
	int north;
	int east;
	int south;
	int west;
	int bottom;
};

void rotn(void);
void rote(void);
void rots(void);
void rotw(void);

Dice d;
int tmp;

int main() {
	int i, q, t, f, r;
	cin >> d.top >> d.south >> d.east >> d.west >> d.north >> d.bottom;
	cin >> q;
	for (i = 0; i < q; i++) {
		cin >> t >> f;
		if (t == d.north)rots();
		else if (t == d.east)rotw();
		else if (t == d.south)rotn();
		else if (t == d.west)rote();
		else if (t == d.bottom) {
			rotn(); rotn();
		}
		if (f == d.north)r = d.west;
		else if (f == d.east)r = d.north;
		else if (f == d.south)r = d.east;
		else if (f == d.west)r = d.south;
		cout << r << endl;
	}
	return 0;
}

void rotn(void) {
	tmp = d.top;
	d.top = d.south;
	d.south = d.bottom;
	d.bottom = d.north;
	d.north = tmp;
}

void rote(void) {
	tmp = d.top;
	d.top = d.west;
	d.west = d.bottom;
	d.bottom = d.east;
	d.east = tmp;
}

void rots(void) {
	tmp = d.top;
	d.top = d.north;
	d.north = d.bottom;
	d.bottom = d.south;
	d.south = tmp;
}
void rotw(void) {
	tmp = d.top;
	d.top = d.east;
	d.east = d.bottom;
	d.bottom = d.west;
	d.west = tmp;
}