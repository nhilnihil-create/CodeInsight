#include <iostream>
using namespace std;
class Card {
public:
	int num;
	char ch;
};
inline void bubbleSort(Card a[], int n){
	bool flag = 1;
	for (int i = 0; flag; i++) {
		flag = 0;
		for (int j = n - 1; j >= i + 1; j--) {
			if (a[j].num < a[j - 1].num) {
				swap(a[j], a[j - 1]);
				flag = 1;
			}
		}
	}
}
inline void selectionSort(Card a[], int n) {
	for (int i = 0; i < n-1; i++) {
		int minj = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j].num < a[minj].num) {
				minj = j;
			}
		}
		swap(a[i], a[minj]);
	}
}
inline void put(Card a[], int n) {
	cout << a[0].ch << a[0].num;
	for (int i = 1; i < n; i++) {
		cout << ' ' << a[i].ch << a[i].num;
	}
	cout << endl;
}
inline bool isStable(Card c1[], Card c2[], int n) {
	for (int i = 0; i < n; i++) {
		if (c1[i].ch != c2[i].ch)
			return false;
	}
	return true;
}
int main() {
	const int n = 36;
	Card ar1[n], ar2[n];
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> ar1[i].ch >> ar1[i].num;
	}
	for (int i = 0; i < num; i++)
		ar2[i] = ar1[i];
	bubbleSort(ar1, num);
	put(ar1, num);
	cout << "Stable" << endl;
	selectionSort(ar2, num);
	put(ar2, num);
	if (isStable(ar1, ar2, num)) 
		cout << "Stable" << endl;
	else cout << "Not stable" << endl;
	
	return 0;
}