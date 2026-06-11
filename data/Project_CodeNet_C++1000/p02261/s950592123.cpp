#include <iostream>

using namespace std;

static const int MAX = 36;

struct Card {
  char suit;
  int value;
};

void bubble (struct Card A[], int N) {

  bool flag = 1;

  for (int i = 0; flag; i++) {
    flag = 0;
    for (int j = N-1; i < j; j--) {
      if (A[j].value < A[j-1].value) {
        Card a = A[j-1];
        A[j-1] = A[j];
        A[j] = a;
        flag = 1;
      }
    }
  }

}

void selection (struct Card A[], int N) {

  for (int i = 0; i < N; i++) {
    int minj = i;
    Card origin = A[i];
    for (int j = i; j < N; j++) {
      if (A[j].value < A[minj].value) {
        minj = j;
      }
    }

    if (i != minj) {
      A[i] = A[minj];
      A[minj] = origin;
    }
  }

}

void print (struct Card A[], int N) {
  for (int i = 0; i < N; i++) {
    if (i > 0) cout << " ";
    cout << A[i].suit << A[i].value;
  }
  cout << endl;
}

bool isStable (struct Card C1[], struct Card C2[], int N) {
  for (int i = 0; i < N; i++) {
    if (C1[i].suit != C2[i].suit) return false;
  }
  return true;
}

int main () {

  int N;
  Card C1[MAX], C2[MAX];

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> C1[i].suit >> C1[i].value;
    C2[i] = C1[i];
  }

  bubble(C1, N);
  selection(C2, N);

  print(C1, N);
  cout << "Stable" << endl;
  print(C2, N);
  if (isStable(C1, C2, N)) {
    cout << "Stable" << endl;
  } else {
    cout << "Not stable" << endl;
  }
}