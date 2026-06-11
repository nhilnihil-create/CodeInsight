#include <iostream>
#define ERA_MAX 246913
#define ROOT_MAX 496

using namespace std;

bool Eratos[ERA_MAX];

int main()
{
	for (int i = 0; i < ERA_MAX; i++) {
		if (i >= 2)
			Eratos[i] = true;
		else
			Eratos[i] = false;
	}
	for (int i = 0; i < ROOT_MAX; i++) {
		if (Eratos[i])
			for (int j = 2 * i; j < ERA_MAX; j += i)
				Eratos[j] = false;
	}
	int n,res;
	while (cin >> n, n) {
		res = 0;
		for (int i = n + 1; i <= 2 * n; i++)
			if (Eratos[i])
				res++;
		cout << res << endl;
	}
	return 0;
}