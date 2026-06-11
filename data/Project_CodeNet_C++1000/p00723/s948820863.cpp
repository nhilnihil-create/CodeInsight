#include <iostream>
#include <string>
using namespace std;

string tmp[71 * 8] = {"\0"};
int p = 0;

void sort(string s[]) {
  for (int i = 0; i < p; i++) {
    for (int j = i; j > 0; j--) {
      if (tmp[j - 1] > tmp[j]) {
	string a = tmp[j - 1];
	tmp[j- 1] = tmp[j];
	tmp[j] = a;
      }
    }
  }
}

string reverse(string s) {
  for (int i = 0; i < s.size() / 2; i++) {
    char t;
    t = s[i];
    s[i] = s[s.size() - i - 1];
    s[s.size() - i - 1] = t;
  }
  return s;
}

void search(string a, string b, int occ) {
  if (occ % 4 == 0 || occ % 4 == 3) a = reverse(a);
  if (occ % 2 == 0) b = reverse(b);

  if (occ <= 4) tmp[p++] = a + b;
  else tmp[p++] = b + a;
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    p = 0;
    for (int i = 0; i < 71 * 8; i++)
      tmp[i] = "\0";
    
    string s, s1, s2;
    cin >> s;
    int len = s.size();
    for (int i = 1; i < len; i++) {
      s1 = s.substr(0, i);
      s2 = s.substr(i);
      for (int j = 1; j < 9; j++)
	search(s1, s2, j);
    }

    sort(tmp);

    int count = 1;
    for (int i = 1; i < p; i++) {
      if (tmp[i - 1] == tmp[i]) continue;
      count++;
    }
    cout << count << endl;
  }
  return 0;
}