#include <iostream>
using namespace std;
double V[51];

void swap (double *x, double *y) {
  double temp;

  temp = *x;
  *x = *y;
  *y = temp;
}

void bubble_sort (double array[], int array_size) {
  int i, j;
  for (i = 0; i < array_size - 1; i++){
    for (j = array_size - 1; j >= i + 1; j--){
      if (array[j] < array[j-1]) { swap(&array[j], &array[j-1]); }
    }
  }
}

int main() {
	int N;
	cin >> N;
	for(int k = 0; k < N; k++){
		cin >> V[k];
	}
	bubble_sort(V, N);

	for(int i = 1; i < N; i++){
		double temp = 0;
		temp = V[i];
		V[i] = (temp + V[i-1]) / 2;
	}
	cout << V[N-1];
	return 0;
}