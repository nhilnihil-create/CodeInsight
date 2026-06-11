#include <iostream>
using namespace std;

int main () {
  int matrix[100][100]={ 0 },input_vector[100]={ 0 },output_vector[100]={ 0 },matrix_row,matrix_column,vector_column,matrix_element,vector_element,output_vector_element=0;
  cin >> matrix_row >> matrix_column;

  for (int i=0;i<matrix_row;++i) {
    for (int j=0;j<matrix_column;++j) {
	  cin >> matrix_element;
	  matrix[i][j] = matrix_element;
	}
  }
  for (int i=0;i<matrix_column;++i) {
	cin >> vector_element;
    input_vector[i] = vector_element;
  }

  for (int i=0;i<matrix_row;++i) {
    for (int j=0;j<matrix_column;++j) {
      output_vector_element = output_vector_element + (input_vector[j] * matrix[i][j]);
    }
    cout << output_vector_element <<endl;
	output_vector_element = 0;
  }
  return 0;
}