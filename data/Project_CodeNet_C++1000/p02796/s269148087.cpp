#include<iostream>
using namespace std;
int X[1000000], LL[1000000];
void margesort(int a[], int a_len, int left, int right);

int main() {

	int n;
	cin >> n;
	int i;
	for (i = 0; i < n; i++) {
		cin >> X[i] >> LL[i];
		X[i] = X[i] + LL[i];
	}
	margesort(X, n, 0, n - 1);
	int rcounter = 1;
	
	int rightmost = X[0];

	for (i = 1; i < n; i++) {
		if (X[i] - 2 * LL[i] >= rightmost) {
			rightmost = X[i];
			rcounter++;
		}
	}

	cout << rcounter << endl;
	return 0;
	//A
	/*
	int h, w, n;
	cin >> h;
	cin >> w;
	cin >> n;

	int max;
	if (h > w) {
		max = h;
	}
	else { max = w; }
	if (n % max == 0) {
		cout << n / max << endl;
	}
	else {
		cout << (n - (n % max)) / max + 1 << endl;
	}
	return 0;*/

}



int temp[1000000];
int tempb[1000000];

void margesort(int a[], int a_len, int left, int right)
{
	int i, j, mid, L, R;

	if (right <= left)
		return;

	mid = (left + right) / 2;
	margesort(a, mid, left, mid);
	margesort(a, a_len - mid, mid + 1, right);

	for (i = left; i <= mid; i++){
		temp[i] = a[i];
		tempb[i] = LL[i];
	}
	for (i = mid + 1, j = right; i <= right; i++, j--) {
		temp[i] = a[j];
		tempb[i] = LL[j];
	}

	L = left;
	R = right;

	for (i = left; i <= right; i++)
	{
		if (temp[L] <= temp[R])
		{
			a[i] = temp[L];
			LL[i] = tempb[L];
			L++;
		}
		else
		{
			a[i] = temp[R];
			LL[i] = tempb[R];
			R--;
		}
	}
}

