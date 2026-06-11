#include <iostream>
using namespace std;

int main () {
  int numbers_of_row,numbers_of_columns;
  cin >> numbers_of_row >> numbers_of_columns;
  int row[numbers_of_row][numbers_of_columns] = { 0 };
  for (int i=0;i<numbers_of_row;++i) {
    int sum_of_rows = 0;
  	for (int j=0;j<numbers_of_columns;++j) {
	  cin >> row[i][j];
      cout << row[i][j] << " ";
	  sum_of_rows = sum_of_rows + row[i][j];
	}
	cout << sum_of_rows << endl;
  }

  int sum_of_a_column = 0;
  int sum_of_last_row = 0;
  for (int j=0;j<numbers_of_columns;++j) {
    for (int i=0;i<numbers_of_row;++i) {
	sum_of_a_column = sum_of_a_column + row[i][j];
	}
	cout << sum_of_a_column << " ";
	sum_of_last_row = sum_of_last_row + sum_of_a_column;
	sum_of_a_column = 0;
  }
  cout << sum_of_last_row << endl;
  return 0;
}