
#include <iostream>
#include <string>
#include <vector>

namespace ABC169
{
  using namespace std;

  /// 文字列を分割する
  std::vector<string> split(string str, string sep)
  {
    vector<string> ret; ret.clear();
    int cursor = 0;
    auto pos = str.find(sep, cursor);
    while (pos != -1)
    {
      // セパレータまでを切り取ってつっこむ
      ret.push_back(str.substr(cursor, pos - cursor));
      cursor = pos + sep.size();
      pos = str.find(sep, cursor);
    }

    // 残りを詰め込む
    if (cursor < str.size() - 1) {
      ret.push_back(str.substr(cursor, str.size() - cursor));
    }
    return ret;
  }

  class C
  {
  public:
    C() = default;
    ~C() = default;


    void Run()
    {
      long long A;
      std::string B_str;

      std::cin >> A;
      std::cin >> B_str;

      auto r = split(B_str, ".");
      long long B_upper = std::atoll( r.at(0).c_str() );
      long long B_lower = std::atoll( r.at(1).c_str());

      auto upper = A * B_upper;
      auto lower = A * B_lower;

      auto answer = upper + (lower / 100);

      std::cout << answer << std::endl;
    }
  };

}
int main()
{

  ABC169::C prob;
  prob.Run();

  return 0;
}
