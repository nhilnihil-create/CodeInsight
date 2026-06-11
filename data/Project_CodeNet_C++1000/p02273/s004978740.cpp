
#include <iostream>
#include <algorithm>
#include <assert.h>
#include <string>

using namespace std;

int tempmarge[1000100];

int N, A[10000000];

int preorder[1000], inorder[1000];

bool bsearch(const int array[], int left, int right, int value) {
	while (left + 1 < right) {
		int med = (left + right) / 2;
		if (array[med] > value)right = med;
		else left = med;
	}
	return left < right  && array[left] == value;
}

long long int MargeSort(int x[], int left, int right) {
	long long int mid, i, j, k, cl, cr, c;

	if (left >= right)
		return 0;

	mid = (left + right) / 2;
	cl = MargeSort(x, left, mid);
	cr = MargeSort(x, mid + 1, right);


	for (i = left; i <= mid; i++)
		tempmarge[i] = x[i];
	for (i = mid + 1, j = right; i <= right; i++, j--)
		tempmarge[i] = x[j];

	i = left;
	j = right;
	c = 0;
	for (k = left; k <= right; k++)
		if (tempmarge[i] <= tempmarge[j])
			x[k] = tempmarge[i++];
		else {
			c += mid + 1 - i;
			x[k] = tempmarge[j--];
		}

	return c + cl + cr;
}

void recover(int fp, int lp, int fi, int li) {
	int root, i;
	for (i = fi; i < li + 1; i++) {
		if (preorder[fp] == inorder[i]) break;
	}
	root = i;
	if (fi < root) {
		recover(fp + 1, fp + root - fi, fi, root - 1);
		cout << " ";
	}
	if (root < li) {
		recover(fp + root - fi + 1, lp, root + 1, li);
		cout << " ";
	}
	cout << inorder[root];
}

void koch(double p1[2], double p2[2], double tol) {
	double s[2], t[2], u[2];
	
	if (sqrt(pow((p1[0] - p2[0]), 2.0) + pow((p1[1] - p2[1]), 2.0)) > tol ){
		s[0] = (p1[0] * 2 + p2[0]) / 3;
		s[1] = (p1[1] * 2 + p2[1]) / 3;
		t[0] = (p1[0] + p2[0] * 2) / 3;
		t[1] = (p1[1] + p2[1] * 2) / 3;
		u[0] = s[0] + (t[0] - s[0])*0.5 - (t[1] - s[1])*sqrt(3.0) / 2;
		u[1] = s[1] + (t[0] - s[0])*sqrt(3.0) / 2 + (t[1] - s[1])*0.5;

		koch(p1, s, tol);

		cout << s[0] << " " << s[1] << endl;

		koch(s, u, tol);

		cout << u[0] << " " << u[1] << endl;

		koch(u, t, tol);

		cout << t[0] << " " << t[1] << endl;

		koch(t, p2, tol);
	}
}

int main() {
	
	cin >> N;
	
	double tol = 100/pow(3,N)+0.0001;

	double p1[2] = { 0,0 };
	double p2[2] = { 100,0 };

	cout << p1[0] << " " << p1[1] << endl;

	koch(p1, p2, tol);

	cout << p2[0] << " " << p2[1] << endl;

	cin >> N;

	return 0;
}