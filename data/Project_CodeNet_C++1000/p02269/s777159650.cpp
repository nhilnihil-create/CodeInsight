#include <cstdio>
#include <cstdlib>
#include <cstring>

const int STR_LENGTH = 13;
const int M = 1000117;

char T[M][STR_LENGTH];

int h1(int k) { return k % M; }
int h2(int k) { return 1 + (k % (M - 1)); }
int h(int k, int i) { return (h1(k) + i * h2(k)) % M;}

int char2int(char c) {
  if (c == 'A') return 1;
  if (c == 'C') return 2;
  if (c == 'G') return 3;
  if (c == 'T') return 4;
  return 0;
}

int genKey(char str[]) {
  int key = 0;
  int p = 5;
  for (int i = 0; i < std::strlen(str); ++i) {
    key += p * char2int(str[i]);
    p *= 5;
  }
  return key;
}

bool insert(char str[]) {
  int key = genKey(str);
  for (int i = 0;; ++i) {
    int j = h(key, i);
    if (std::strcmp(T[j], str) == 0) return false;
    else if (std::strlen(T[j]) == 0) {
      std::strcpy(T[j], str);
      return true;
    }
  }
  return false;
}

bool find(char str[]) {
  int key = genKey(str);
  for (int i = 0;; ++i) {
    int j = h(key, i);
    if (std::strcmp(T[j],str) == 0) return true;
    else if (std::strlen(T[j]) == 0) return false;
  }
  return false;
}

int main() {
  int n;
  char com[6], str[STR_LENGTH];
  for (int i = 0; i < M; ++i) T[i][0] = '\0';

  std::scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    std::scanf("%s%s", com, str);
    if (com[0] == 'i') insert(str);
    else if (com[0] == 'f') {
      bool result = find(str);
      std::printf("%s\n", result ? "yes" : "no");
    }
  }
}

