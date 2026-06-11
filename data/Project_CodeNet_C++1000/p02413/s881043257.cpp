#include <iostream>

int main(void)
{
	using namespace std;

	int r,c;

	cin >> r;
	cin >> c;

	int Mat[r][c];
	int sums_row[r] = {0}, sums_colmn[c] = {0}, sums_all = 0;

	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			cin >> Mat[i][j];
			sums_row[i] += Mat[i][j];
		}
	}

	for(int j=0; j<c ;j++){
		for(int i=0; i<r; i++)	sums_colmn[j] += Mat[i][j];
		sums_all += sums_colmn[j];
	}

	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++)	cout << Mat[i][j] << " ";
		cout << sums_row[i] <<endl;
	}
	for(int j=0; j<c; j++)	cout << sums_colmn[j] << " ";
	cout << sums_all << endl;

	return 0;
}