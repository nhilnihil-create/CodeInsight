#include <iostream>
using namespace std;

int main()
{
  int red, green, blue, operation, count;
  count = 0;

  cin >> red >> green >> blue;
  cin >> operation;

  if(red >= green)
  {
    while(red >= green)
    {
      green = green * 2;
      count++;
    }
  }

  if(green >= blue)
  {
    //cout << count << end;
    while (green >= blue)
    {
      blue = blue * 2;
      count++;
    }
  }

  //cout << count << endl;

  if(count <= operation)
  {
    cout << "Yes" << endl;
  }

  if(count > operation)
  {
    cout << "No" << endl;
  }
}

  /*두번째꺼가 첫번째꺼보다 작으면 커질때까지 두배시키고
  세번째 두번째 비교
  카운팅이 k보다 작거나 같으면 ok
  크면 안된다*/
