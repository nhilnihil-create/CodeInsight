#include <iostream>
using namespace std;

//typedef struct CARD {
//	char my_type[5] = {'S','H','C','D', 0};
//	int my_num[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
//}CARDS;

int main()
{
//	CARDS cardS;
	char my_type[5] = { 'S','H','C','D', 0 };
	int my_num[13] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };

	char card_type;
	int card_num,max, count = 0;
	int hit[4][13] = { { 0 }, { 0 } };

	cin >> max;

	while (count < max)
	{
		cin >> card_type >> card_num;
		for (int i = 0; i < 4; i++) {
			if (my_type[i] == card_type) {
				for (int j = 0; j < 13; j++) {
					if (my_num[j] == card_num) {
						hit[i][j] = 1;
					}
				}
			}
		}
		count++;
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			if (hit[i][j] == 0) {
				cout << my_type[i] << ' ' << my_num[j] << endl;
			}
		}
	}

    return 0;
}