#include <iostream>
using namespace std;

string regist()
{
  int count;
  count = 0;
  string id, replace;
  getline(cin, id);
  getline(cin, replace);

//카운트 개념 생각났다
  for (int i = 0; i < id.length(); i++)
  {
    if(id[i] == replace[i])
    count++;
  }
  if(count == id.length())
  {
    return "Yes";
  }
  else
  {
    return "No";
  }
}

int main()
{
  cout << regist() << endl;
}
