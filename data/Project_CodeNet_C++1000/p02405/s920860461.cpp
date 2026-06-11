#include<iostream>
#include<vector>
using namespace std;

class Input
{
  public:
    int height;
    int width;
    Input(int a,int b);
};

Input::Input(int a, int b)
{
  height = a;
  width = b;
}

int main(int argc,char* argv[])
{
  int height, width;
  vector<Input> inputs;
  int i=0;
  int j=0;
  while(1)
  {
    cin >> height >> width;
    if(height==0 && width==0) break;
    inputs.push_back(Input(height,width));
  }
  for(auto input: inputs)
  {
    j = 0;
    while(j<input.height)
    {
      i=0;
      while(i<input.width)
      {
        cout << '#';
        i++;
        if(i==input.width) break;
        cout << '.';
        i++;
      }
      cout << endl;
      j++;
      if(j==input.height) break;
      i = 0;
      while(i<input.width)
      {
        cout << '.';
        i++;
        if(i==input.width) break;
        cout << '#';
        i++;
      }
      cout << endl;
      j++;
    }
    cout << endl;
  }
}