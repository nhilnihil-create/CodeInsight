#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main(){
#ifdef CIN
	ifstream cin("input.txt");
	ofstream cout("output.txt");

#endif

	int h, w;

	while (true)
	{

		cin >> h >> w;

		if (h == 0 && w == 0) break;
		for (int k = 1; k <= w; k++)
		{
			cout << "#";

		}
		cout << endl;
		for (int i = 1; i < h-1; i++)
		{
			cout << '#';
			for (int j = 2; j < w; j++)
			{
				cout << ".";

			}
			cout << '#';
			cout << endl;
		}
		for (int l = 1; l <= w; l++)
		{
			cout << "#";

		}
		cout << endl << endl;
	}


}