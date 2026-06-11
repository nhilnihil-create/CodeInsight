#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
	uint64_t X;
	cin >> X;
	int64_t gohyaaku = 0;
	int64_t goen = 0;
	

    gohyaaku = int(X / 500);
    goen = X%500;

	goen = int(goen/5);
	
	int64_t out = 1000 * gohyaaku + 5 * goen;
	
	cout << out << endl;
	
	return 0;
}
