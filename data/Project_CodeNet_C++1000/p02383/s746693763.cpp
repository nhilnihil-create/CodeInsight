#include<iostream>
using namespace std;
class dice
{
  private:
  int status[6];
  public:
  dice();
  int showup(void);
  void rotate(char);
};

dice::dice()
{
  for(int i=0;i<6;i++)
    cin>>status[i];
}


int dice::showup()
{
  cout<<status[0]<<endl;
}

void dice::rotate(char s)
{
  switch(s)
  {
    int tmp;
    case 'N':
      tmp=status[0];
      status[0]=status[1];
      status[1]=status[5];
      status[5]=status[4];
      status[4]=tmp;
      break;
    case 'E':
      tmp=status[0];
      status[0]=status[3];
      status[3]=status[5];
      status[5]=status[2];
      status[2]=tmp;
      break;
    case 'W':
      tmp=status[0];
      status[0]=status[2];
      status[2]=status[5];
      status[5]=status[3];
      status[3]=tmp;
      break;
    case 'S':
      tmp=status[0];
      status[0]=status[4];
      status[4]=status[5];
      status[5]=status[1];
      status[1]=tmp;
      break;
  }
}

int main()
{
  dice di1;
  string s;
  cin>>s;
  for(int i=0;s[i];i++)
    di1.rotate(s[i]);
  di1.showup();
}