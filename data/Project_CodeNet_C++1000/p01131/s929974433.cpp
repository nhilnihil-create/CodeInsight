#include <iostream>
#include <string>

using namespace std;

char m[][6] = {
  {},
  {5, '.', ',', '!', '?', ' '}, // 1
  {3, 'a', 'b', 'c'}, // 2
  {3, 'd', 'e', 'f'}, // 3
  {3, 'g', 'h', 'i'}, // 4
  {3, 'j', 'k', 'l'}, // 5
  {3, 'm', 'n', 'o'}, // 6
  {4, 'p', 'q', 'r', 's'}, // 7
  {3, 't', 'u', 'v'}, // 8
  {4, 'w', 'x', 'y', 'z'}, // 9
};

int main() {
  int N;
  cin >> N;

  while (N--) {
    string str;
    cin >> str;

    int s = 0, cnt = -1;
    for (int i=0; i<str.size(); i++) {
      int d = str[i] - '0';
      if (d == 0) {
        if (s != 0) { cout << m[s][ (cnt % m[s][0]) + 1 ]; }
        s = 0; cnt = -1;
      } else {
        s = d;
        cnt++;
      }
    }

    cout << endl;
  }

  return 0;
}