#include<iostream>
#include<string>

using namespace std;

void change(int *x, int *y);
void BubbleSort(struct Card c[], int n);
void SelectionSort(struct Card c[], int n);
bool isStable(struct Card c1[], struct Card c2[], int n);
void print(struct Card c[], int n);

struct Card{
		char suit, value;
};

int main(void)
{
	int n;
	Card c1[36], c2[36];
	
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> c1[i].suit >> c1[i].value;
	for(int i = 0; i < n; ++i) c2[i] = c1[i];
	BubbleSort(c1, n);
	SelectionSort(c2, n);
	
	print(c1, n);
	cout << "Stable" << endl;
	print(c2, n);
	if(isStable(c1, c2, n))
		cout << "Stable" << endl;
	else cout << "Not stable" << endl;
	
	return 0;
}

void change(struct Card *x, struct Card *y){
	struct Card tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
	
}

void BubbleSort(struct Card c[], int n){
	bool flag = true;
	while(flag){
		flag = false;
		for(int i = n - 1; i > 0; --i){
			if(c[i].value < c[i-1].value){
				change(&c[i], &c[i-1]);
				flag = true;
			}
		}
	}
}

void SelectionSort(struct Card c[], int n){
	int min;
	for(int i = 0; i < n; ++i){
		min = i;
		for(int j = i; j < n; ++j)
			if(c[min].value > c[j].value) min = j;
		change(&c[min], &c[i]);
	}
}

bool isStable(struct Card c1[], struct Card c2[], int n){
	for(int i = 0; i < n; ++i){
		if(c1[i].suit != c2[i].suit) return false;
	}
	return true;
}

void print(struct Card c[], int n){
	for(int i = 0; i < n; ++i){
		if(i > 0) cout << ' ';
		cout << c[i].suit << c[i].value;
	}
	cout << endl;
}