#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int studentNum,tmp = 0;
	double SD,D = 0.0,ave = 0.0;
	vector<int> score;
	cout.precision(15);

	while (cin >> studentNum&&studentNum) {

		for (int i = 0; i < studentNum; i++)
		{
			cin >> tmp;
			ave += tmp;
			score.push_back(tmp);
		}

		ave /= studentNum;

		for (int i = 0; i < studentNum; i++) D += pow((score[i] - ave), 2);
		SD = sqrt(D / (double)studentNum);
		
		cout << SD << endl;

		D = 0.0;
		ave = 0;
		SD = 0;
		score.clear();
	}

    return 0;
}