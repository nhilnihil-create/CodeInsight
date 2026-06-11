#include<iostream>
#include<string>
#include<vector>
using namespace std;
class dice{
public:
	int a, b, c, d, e, f;
	int g, h, i, j, k, l;
	void east() {
		prep();
		a = j;
		b = h;
		c = g;
		d = l;
		e = k;
		f = i;
	}
	void west() {
		prep();
		a = i;
		b = h;
		c = l;
		d = g;
		e = k;
		f = j;
	}
	void north() {
		prep();
		a = h;
		b = l;
		c = i;
		d = j;
		e = g;
		f = k;
	}
	void south() {
		prep();
		a = k;
		b = g;
		c = i;
		d = j;
		e = l;
		f = h;
	}
private:
	void prep() {
		g = a;
		h = b;
		i = c;
		j = d;
		k = e;
		l = f;
	}
};
int main() {
	dice dice1;
	cin >> dice1.a;
	cin >> dice1.b;
	cin >> dice1.c;
	cin >> dice1.d;
	cin >> dice1.e;
	cin >> dice1.f;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == 'N'){
			dice1.north();
		}
		else if (s[i] == 'E'){
			dice1.east();
		}
		else if (s[i] == 'W'){
			dice1.west();
		}
		else if (s[i] == 'S'){
			dice1.south();
		}
	}
	cout << dice1.a << endl;
	char c;
	cin >> c;
}