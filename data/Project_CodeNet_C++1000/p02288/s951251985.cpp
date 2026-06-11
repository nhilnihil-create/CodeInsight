#include<stdio.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void maxHeapify(int A[], int i, int H) {
	int l = (2*i)+1;
	int r = (2*i)+2;
	int largest;

	if(l<H && A[l]>A[i]) 
	{
		largest = l;
	}
	else 
	{
		largest = i;
	}
	
	if(r<H && A[r]>A[largest]) 
	{
		largest = r;
	}
	if(largest != i) {
		swap(&A[i], &A[largest]);
		maxHeapify(A, largest, H);
	}
}

void buildMaxHeap(int A[], int H) {
	for(int i = (H/2)-1; i >= 0; i--) {
		maxHeapify(A, i, H);
	}
}

int main() {
	int H;
	int A[500005];
	scanf("%d", &H);
	for(int i = 0; i < H; i++) 
	{
		scanf("%d", &A[i]);
	}
	buildMaxHeap(A, H);
	for(int i = 0; i < H; i++) {
		printf(" %d", A[i]);
	}
	printf("\n");
	
	return 0;
}


