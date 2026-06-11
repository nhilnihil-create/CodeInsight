#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

std::vector<int> find_all(const std::string str, const std::string subStr) {
    std::vector<int> result;

    int subStrSize = subStr.size();
    size_t pos = str.find(subStr);

    while (pos != std::string::npos) {
        result.push_back(pos);
        pos = str.find(subStr, pos + subStrSize);
    }

    return result;
}

int main() {
  int n;
  string s;
  cin >> n >> s;
  std::vector<int> findVec = find_all(s, "ABC");
  cout << findVec.size() << endl;
}
