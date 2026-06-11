#include <stdio.h>
 
void bubbleSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int swap = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = swap;
			}
		}
	}
}
 
int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	int ctr = 0;
	//	bubbleSort(arr, n);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				if (arr[i] != arr[j] && arr[j] != arr[k] && arr[i] != arr[k] && arr[i] + arr[j] > arr[k] && arr[i] + arr[k] > arr[j] && arr[k] + arr[j] > arr[i]) {
					ctr++;
				}
			}
		}
	}
	printf("%d\n", ctr);
	return 0;
}