#include <iostream>
using namespace std;

struct Card { char suit; int value;};

void selectionsort(struct Card A[], int N) {

  for (int i = 0; i< N; i++) {

    int minj = i;

    for (int j = i; j < N; j++) {

      if (A[j].value < A[minj].value) minj = j;
    }

    swap(A[i], A[minj]);
  }
  
}

void bubblesort(struct Card A[], int N) {
  int flag = 1;

  while (flag) {
    flag = 0;
    for (int i = N-1; i > 0; i--) {
      if (A[i].value < A[i-1].value) {
	swap(A[i], A[i-1]);
	flag = 1;
      }
    }
  }
}


void print(struct Card A[], int N) {
  for (int i = 0; i < N; i++) {

    if (i != N-1) cout << A[i].suit << A[i].value << " ";
    else cout << A[i].suit << A[i].value << endl;
  }
}

bool isstable(struct Card A[], struct Card B[], int N) {

  for(int i = 0; i < N; i++) {
    if (A[i].suit != B[i].suit) return false;
  }
  return true;
}


int main() {

  Card C1[100], C2[100];
  int N;

  cin >> N;

  for (int i=0; i < N; i++) {
    cin >> C1[i].suit >> C1[i].value;
  }

  for (int i = 0; i < N; i++) C2[i] = C1[i];

  bubblesort(C1, N);
  selectionsort(C2, N);

  print(C1, N);
  cout << "Stable" << endl;

  print(C2, N);
  if (isstable(C2, C1, N)) cout << "Stable" << endl;
  else cout << "Not stable" << endl;

  return 0;
}