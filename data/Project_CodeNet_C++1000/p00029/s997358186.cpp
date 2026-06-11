#include <cstdio>
#include <cstring>
#include <string>
#include <map>
using namespace std;

char buf[1001];
map<string, int> cnt;
string mode;
string longest;

int main() {
  while (1) {
    if (scanf("%s", buf) != 1) break;

    string word = buf;
    int n = strlen(buf);
    if (n > longest.size()) longest = buf;
    ++cnt[word];
    if (cnt[word] > cnt[mode]) mode = word;
  }

  printf("%s %s\n", mode.c_str(), longest.c_str());
}