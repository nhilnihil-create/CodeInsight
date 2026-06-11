#include <iostream>
#include <vector>
#include <string>
using namespace std;


class dice {
public:
	dice(int* a) {
		set(a[0], a[1], a[2], a[3], a[4], a[5]);
	}
	dice(int& a, int& b, int& c, int& d, int &e, int& f) {
		set(a, b, c, d, e, f);
	}
	void turn(int n) {
		if (n < 4)
		{
			turndice(n);
			return;
		}
		switch (n)
		{
		case 'N':
			turndice(0);
			break;
		case 'E':
			turndice(1);
			break;
		case 'S':
			turndice(2);
			break;
		case 'W':
			turndice(3);
			break;
		}

	}

	int getcurrent(void) { return label[0]; }

private:

	int label[6];

	void set(int& a, int& b, int& c, int& d, int &e, int& f) {
		label[0] = a; 
		label[1] = b; 
		label[2] = c; 
		label[3] = d; 
		label[4] = e; 
		label[5] = f; 
	}
	void turndice(int n)
	{
		int m = (n > 1) ? n - 2 : n + 2;
		int f[] = { 1, 3, 4, 2 };
		int tmp;

		tmp = label[0];
		label[0] = label[f[n]];
		label[f[n]] = label[5];
		label[5] = label[f[m]];
		label[f[m]] = tmp;
	}

};

#define A

#ifdef A
int main(void)
{
	int in[6];
	for (auto &a :in)
	{
		cin >> a;
	}
	dice d(in);
	string oder;
	cin >> oder;
	for (size_t i = 0; i < oder.size(); i++)
	{
		d.turn(oder[i]);
	}

	cout << d.getcurrent() << endl;


	return 0;
}
#endif // A