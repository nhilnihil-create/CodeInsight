#include <cstdio>
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

#define rev(s) (vector<char>((s).rbegin(), (s).rend()))
#define HASH_SIZE 30011
#define a 1049

int hash(vector<char> str)
{
  int n = 0;
  int pow = 1;
  for (unsigned int i = 0; i < str.size(); i++) {
    n += (pow * (str[i] - 'a')) % HASH_SIZE;
    pow *= 26;
    pow %= HASH_SIZE;
  }
  return n % HASH_SIZE;
}

class hash_table {
public:
  vector<vector<char> > h;
  bool operator[](vector<char> str) {
    int key = hash(str);
    //cout << string(str.begin(), str.end()) << ":" << key << endl;
    for (int i = 0; i < HASH_SIZE; i++) {
      if (h[key].empty()) {
	h[key] = str;
	return true;
      } else if (str == h[key]) {
	return false;
      } else {
	//printf("hit!\n");
	key = (key * key + a) % HASH_SIZE;
      }
    }
    //printf("!!\n");
    h[key] = str;
    return true;
  }
  hash_table():h(HASH_SIZE) {}
};

vector<char>operator+(const vector<char>& lhs, const vector<char>& rhs)
{
  vector<char> result = lhs;
  result.insert(result.end(), rhs.begin(), rhs.end());
  return result; 
}

int getline(char* str)
{
  char c;
  int idx = 0;
  while ((c = getchar()) != EOF) {
    //printf("%d\n", idx);
    if (c == '\n') {break;}
    str[idx++] = c;
    //printf("%c\n", str[idx - 1]);
  }
  return idx;
}

int main() {
  int N;
  scanf("%d ", &N);
  while (N--) {
    char str[100];
    int end = getline(str);
    //if (N == 3) {printf("hoge\n");}
   
    hash_table bag;

    int c = 0;
    bag[vector<char>(str, str + end)];
    c++;
    for (int i=1; i< end; i++) {
      vector<char> head(str, str + i);
      vector<char> tail(str + i, str + end);
      
      //if (bag[head + tail]) c++;
      if (bag[rev(head) + tail]) c++;
      if (bag[head + rev(tail)]) c++;
      if (bag[rev(head) + rev(tail)]) c++;
      if (bag[tail + head]) c++;
      if (bag[rev(tail) + head]) c++;
      if (bag[tail + rev(head)]) c++;
      if (bag[rev(tail) + rev(head)]) c++;
    }
    printf("%d\n", c);
  }
  return 0;
}