#include <iostream>
using namespace std;

int main()
{
  int h1, h2, m1, m2, studytime, diff,result;
  diff = 0;
  result = 0;
  cin >> h1 >> m1 >> h2 >> m2 >> studytime;

  if (m1 == m2)
  {
    diff = h2 - h1;
    diff = diff * 60 - studytime;
  }
  else if(m2 > m1)
  {
    diff = h2 - h1;
    diff = diff * 60 + (m2- m1)-studytime;
    //cout << diff << endl;
    //result = diff / studytime;
  }
  else
  {
    h2 = h2 - 1;
    m2 = m2 + 60;
    diff = h2 - h1;
    diff = diff * 60 + (m2- m1) - studytime;
    //result = diff / studytime;
  }
  cout << diff << endl;
}
