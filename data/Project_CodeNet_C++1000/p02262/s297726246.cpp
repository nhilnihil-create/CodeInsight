#include <iostream>
#include <cstdio>

using namespace std;

void insertionSort(int *, int, int);
void shellSort(int *, int);

int cnt = 0;
int m = 13;

void print_array(int *x, int n, bool f)
{
	if(f)
	{
		for (int k = n - 1; k >= 0; k--)
		{
			if (k == 0)
			{
				printf("%d\n", x[k]);
			}
			else
			{
				printf("%d ", x[k]);
			}
		}
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			printf("%d\n", x[i]);
		}
	}
}


int main(int argc, char const *argv[])
{
	int inputSize = 0;
	cin >> inputSize;
	int input[inputSize];

	for (int i = 0; i < inputSize; ++i)
	{
		cin >> input[i];
	}

	shellSort(input, inputSize);
	printf("%d\n", cnt);
	print_array(input, inputSize, false);

	return 0;
}


void insertionSort(int *array, int arraySize, int g)
{
	for (int i = g; i < arraySize; ++i)
	{
		int key = array[i];
		int j = i - g;
		while(j >= 0 && array[j] > key)
		{
			array[j + g] = array[j];
			j -= g;
			cnt++;
		}
		array[j + g] = key;
	}
}


/* g 離れた数に対して挿入ソートを行う */
void shellSort(int *array, int arraySize)
{
	int G[13] = {1, 4, 13, 40, 121, 364, 1093, 3280, 9841, 29524, 88573, 265720, 797161};

	while(G[m-1] > arraySize) m--;

	printf("%d\n", m);
	print_array(G, m, true);

	for (int i = m - 1; i >= 0; i--)
	{
		insertionSort(array, arraySize, G[i]);
	}
}