#include<iostream>
using namespace std;
class dice
{
  private:
  int status[6];
  public:
  dice();
  int showright(void);
  bool is(int,int);
  bool isfront(int);
  void rotate(char);
};

dice::dice()
{
  for(int i=0;i<6;i++)
    cin>>status[i];
}

bool dice::isfront(int a)
{
  if(status[1]==a) return true;
  else return false;
}

bool dice::is(int a,int b)
{
  if((status[0]==a)&&(status[1]==b)) return true;
  else return false;
}

int dice::showright()
{
  cout<<status[2]<<endl;
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
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    int a,b;
    cin>>a>>b;
    int j;
    for(j=0;j<=3;j++)
    {
      if(di1.isfront(b)||di1.is(a,b)) break;
      di1.rotate('N');
    }
    if(j==4)
    {
      di1.rotate('E');
      di1.rotate('S');
    }
    if(!di1.isfront(b))
    {
      di1.rotate('N');
      di1.rotate('N');
    }
    for(j=0;j<3;j++)
    {
      if(di1.is(a,b)) break;
      di1.rotate('E');
    }
    di1.showright();
  }
}