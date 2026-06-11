#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct Info {
  string word;
  int length;
  int hist;
};

vector<Info> words;
vector<Info>::iterator it;

void init(string s) {
  string word;
  stringstream ss;

  for (ss << s; !ss.eof();) {
    ss >> word;
    bool flag = false;
    for (it = words.begin(); it != words.end(); it++) {
      if (it->word == word) {
        flag = true;
        it->hist += 1;
      }
    }
    if (!flag) {
      Info info = { word, word.length(), 1 };
      words.push_back(info);
    }
  }
}

string find() {
  string mode = "", max = "";
  int m1 = 0, m2 = 0;
  
  for (it = words.begin(); it != words.end(); it++) {
    if (m1 < it->hist) m1 = it->hist;
    if (m2 < it->length) m2 = it->length;
  }
  
  for (it = words.begin(); it != words.end(); it++) {
    if (m1 == it->hist) mode = it->word;
    if (m2 == it->length) max = it->word;
  }

  return mode + " " + max;
}

int main() {
  string line, r;

  getline(cin, line);
  init(line);
  r = find();

  cout << r << endl;

  return 0;
}