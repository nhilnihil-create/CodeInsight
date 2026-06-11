#include <iostream>

using namespace std;

int insertion_sort(int *seq, int length, int g) {
  int temp, count = 0;
  int v, j;
  for (int i = g; i < length; i ++) {
    v = seq[i];
    j = i - g;
    while (j >= 0 && seq[j] > v) {
      seq[j + g] = seq[j];
      j = j - g;
      count ++;
    }
    seq[j + g] = v;
  }
  return count;
}

int shellSort(int *A, int n) {
  int cnt = 0, m;
  int i = 1;
  int G[1000000];

  for (int i = 1, j = 0; i < n; j++, i *= 2) {
    G[j] = i;
    m = j;
  }

  cout << m + 1 << endl;
  for (int i = m; i >= 0; i --) {
    cnt += insertion_sort(A, n, G[i]);
    cout << G[i] << " ";
  }
  cout << endl;
  return cnt;

}


int main(){
  int N, count;
  int seq[1000000];
  cin >> N;
  for (int i = 0; i < N; i ++)
    cin >> seq[i];

  count = shellSort(seq, N);
  cout << count << endl;
  for (int k = 0; k < N; k ++)
    cout << seq[k] << endl;
}

