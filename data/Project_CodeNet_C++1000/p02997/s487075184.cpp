#include<iostream>
using namespace std;
long long int gcd(long long int a, long long int b);
long long int lcm(long long int a, long long int b); 
long long int baikan(long long int a, long long int b, long long int c);
void margesort(int a[], int a_len, int left, int right);
int A[200000], B[200000];
int temp[200000];
int temp2[200000];
int main() {

	//E
	int n, k;
	cin >> n >> k;
	if (k > (n - 1) * (n - 2) / 2) {
		cout << -1 << endl;
		return 0;
	}
	if (n == 2) {
		cout << 1 << endl;
		cout << 1 << ' ' << 2 << endl;
		return 0;
	}
	cout << n - 1 + (n - 1) * (n - 2) / 2 - k << endl;
	int i,x,y;
	x = n;
	y = n - 1;
	for (i = 0; i < n - 1 + (n - 1) * (n - 2) / 2 - k; i++) {
		cout << x << ' ' << y << endl;
		y--;
		if (y == 0) {
			x--;
			y = x - 1;
		}
	}
	return 0;

	//D
	/*int i, n;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> A[i] >> B[i];
	}
	margesort(B, n, 0, n - 1);
	//cout << "Sort" << endl;
	//for (i = 0; i < n; i++) {
	//	cout << A[i] << ' ' << B[i]<< endl;
	//}

	long long int sum = 0;
	for (i = 0; i < n; i++) {
		sum = sum + A[i];
		//cout << sum << ' ' << A[i] << ' ' << B[i] << endl;
		if (sum > B[i]) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;*/

	//C
	/*long long int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << b - a + 1 - baikan(a, b, c) -  baikan(a, b, d) + baikan(a, b, lcm(c, d)) << endl;
	return 0;*/

	//B
	/*int n, l;
	cin >> n >> l;
	int k = n * l + n * (n - 1) / 2;
	//cout << k;
	int i;
	int min = l;
	for (i = 0; i < n; i++) {
		if (abs(l + i) < abs(min)) {
			min =  l + i;
		}
	}
	cout << k - min << endl;
	return 0;
	*/

	//A
	/*
	string s;
	cin >> s;
	for (int i = 0; i < 3; i++) {
		if (s[i] == s[i + 1]) {
			cout << "Bad" << endl;
			return 0;
		}
	}
	cout << "Good" << endl;
	return 0;
	*/
}

long long int gcd(long long int a, long long int b) {
	if (a == 0) {
		return b;
	}
	else if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}
long long int lcm(long long int a, long long int b) {
	return a * b / gcd(a, b);
}
long long int baikan(long long int a, long long int b, long long int c) {
	long long int d = b - a + 1;
	if (((b - (d % c)) % c) <= (b % c)) {
		return (d - (d % c)) / c;
	}
	else {
		return (d - (d % c)) / c + 1;
	}
}
void margesort(int a[], int a_len, int left, int right)
{
	int i, j, mid, L, R;

	if (right <= left)
		return;

	mid = (left + right) / 2;
	margesort(a, mid, left, mid);
	margesort(a, a_len - mid, mid + 1, right);

	for (i = left; i <= mid; i++)
	{
		temp[i] = a[i];
		temp2[i] = A[i];
	}
	for (i = mid + 1, j = right; i <= right; i++, j--)
	{
		temp[i] = a[j];
		temp2[i] = A[j];
	}

	L = left;
	R = right;

	for (i = left; i <= right; i++)
	{
		if (temp[L] <= temp[R])
		{
			a[i] = temp[L];
			A[i] = temp2[L];
			L++;
		}
		else
		{
			a[i] = temp[R];
			A[i] = temp2[R];
			R--;
		}
	}
}