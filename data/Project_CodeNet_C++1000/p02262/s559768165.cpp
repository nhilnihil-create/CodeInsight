#include <iostream>
#include <algorithm>
#include <vector>
#include <new>
using namespace std;

int cnt;
int m;
vector<int> v;
	
void insertionSort(int A[], int n, int g) {
	int i,j,tmp;
	for (i = g;i < n;i++) {
		tmp = A[i];
		j = i - g;
		while (j >= 0 && A[j] > tmp) {
			A[j + g] = A[j];
			j = j - g;
			cnt++;
		}
		A[j + g] = tmp;
	}
}

void shellSort(int A[], int n) {
    cnt=0;
    int val=1;
    do{
        v.push_back(val);
        val=val*3+1;
        m++;
    }while(val<n);
	for(int i = 0;i < m;i++)
		insertionSort(A, n, v[m-1-i]);
}

int main() {
	int A[1000000];
	int n;
	cin >> n;
	for (int i = 0;i < n;i++) cin >> A[i];
	shellSort(A, n);
	
	cout << m << endl;
	for (int i = 0;i < m;i++) {
		if (i) cout << " ";
		cout << v[m - 1 - i];
	}
	cout << endl<<cnt<<endl;
	for (int i = 0;i < n;i++) cout << A[i] << endl;

    return 0;
}