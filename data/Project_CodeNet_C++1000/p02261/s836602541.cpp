#include <stdio.h>
#include <math.h>

int makeelem(int suit, int number) { return suit * 256 + number; }
int getsuit(int elem) { return elem >> 8; }
int getvalue(int elem) { return elem & 255; }

int n;
int a[36];
int b[36];
int index[36];

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void bubblesort() {
	for (int i = 0; i < n; i ++) {
		for (int j = n - 1; j >= i + 1; j --) {
			if (getvalue(a[j]) < getvalue(a[j-1])) {
				swap(&a[j], &a[j-1]);
			}
		}
	}
}

void selectionsort() {
	for (int i = 0; i < n; i ++) {
		int mini = i;
		for (int j = i; j < n; j ++) {
			if (getvalue(b[j]) < getvalue(b[mini])) {
				mini = j;
			}
		}
		swap(&b[i], &b[mini]);
		swap(&index[i], &index[mini]);
	}
}

int isstable() {
	int i = 0;
	while (i < n) {
		int val = getvalue(b[i]);
		int prev = index[i];
		i ++;
		while (i < n) {
			if (getvalue(b[i]) != val) { i ++; break; }
			if (prev > index[i]) return 0;
			i ++;
		}
	}
	return 1;
}

void print(int *a) {
	for (int i = 0; i < n; i ++) {
		if (i > 0) printf(" ");
		printf("%c%d", getsuit(a[i]), getvalue(a[i]));
	}
	printf("\n");
}

int main(void) {
	char line[1000];
	scanf("%d\n", &n);
	gets(line);
	for (int i = 0; i < n; i ++) {
		int suit = line[3 * i];
		int value = line[3 * i + 1] - '0';
		a[i] = makeelem(suit, value);
		b[i] = makeelem(suit, value);
	}
	for (int i = 0; i < n; i ++) {
		index[i] = i;
	}
	bubblesort();
	print(a);
	printf("Stable\n");
	selectionsort();
	print(b);
	if (isstable()) { printf("Stable\n"); } else { printf("Not stable\n"); }
	return 0;
}