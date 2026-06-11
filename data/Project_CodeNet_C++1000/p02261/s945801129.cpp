#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N;
string b[36], s[36];

void show() {
  for (int i = 0; i < N; i++) {
    cout << b[i] << (i == N-1 ? '\n' : ' ');
  }
  cout << "Stable" << endl;

  for (int i = 0; i < N; i++) {
    cout << s[i] << (i == N-1 ? '\n' : ' ');
  }
  for (int i = 0; i < N; i++) {
    if(b[i] != s[i]) {
      cout << "Not stable" << endl;
      return;
    }
  }
  cout << "Stable" << endl;

}

void bubble_sort() {
  for (int i = 0; i < N; i++) {
    for (int j = N-1; j > i; j--) {
      if(b[j][1] < b[j-1][1]) {
        swap(b[j], b[j-1]);
      }
    }
  }
}

void selection_sort() {
  for (int i = 0; i < N; i++) {
    int minj = i;
    for (int j = i; j < N; j++) {
      if(s[j][1] < s[minj][1]) minj = j;
    }
    swap(s[i], s[minj]);
  }
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> b[i];
    s[i] = b[i];
  }

  bubble_sort();
  selection_sort();

  show();
}