#include <iostream>

namespace NS20200711Acing
{

  class NumberOfMultiples final
  {
  public:
    NumberOfMultiples() = default;
    ~NumberOfMultiples() = default;

  public:
    void Run();

    void Input();
    void Calc();
    void Output();

  private:
    int m_L;
    int m_R;
    int m_d;
    int m_answer = 0;
  };

  void NumberOfMultiples::Run()
  {
    Input();
    Calc();
    Output();
  }

  void NumberOfMultiples::Input()
  {
    std::cin >> m_L;
    std::cin >> m_R;
    std::cin >> m_d;
  }

  void NumberOfMultiples::Calc()
  {
    int amari = m_L % m_d;

    for (int i = (amari == 0) ?m_L : m_L + ( m_d - amari); i <= m_R; i += m_d)
    {
      m_answer++;
    }
  }

  void NumberOfMultiples::Output()
  {
    std::cout << m_answer << std::endl;
  }

}
int main()
{
  NS20200711Acing::NumberOfMultiples prob;
  prob.Run();

  return 0;
}

