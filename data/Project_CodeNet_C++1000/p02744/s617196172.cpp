#include <iostream>
#include <vector>

int N;
std::vector<char> ans;
int a_int = (char)'a';

void print_string(int idx, int n)
{
  if (idx == N)
  {
    for (auto &e : ans)
      std::cout << e;
    std::cout << std::endl;
    ans.pop_back();
    return;
  }
  for (int i = 0; i < n; i++)
  {
    ans.push_back((char)(a_int + i));
    print_string(idx + 1, n);
  }
  ans.push_back((char)(a_int + n));
  print_string(idx + 1, n + 1);
  ans.pop_back();
  return;
}

int main(int argc, char const *argv[])
{
  std::cin >> N;
  print_string(0, 0);
}