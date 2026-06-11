#include <iostream>

using namespace std;

class cQQ
{
public:
	void output();
};

void cQQ::output()
{
	for (int i = 1; i < 10; ++i)
	{
		for (int j = 1; j < 10; ++j)
		{
			cout << i << "x" << j << "=" << i * j << endl;
		}
	}
}

int main()
{
	cQQ cqq;
	cqq.output();

	return 0;
}