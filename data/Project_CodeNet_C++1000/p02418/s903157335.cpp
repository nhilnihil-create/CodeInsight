#include <iostream>
using namespace std;

int main()
{
  char s[100];
  char p[100];
  cin >> s >> p;
  int i=0;
  while(s[i]!='\0')
    i++;
  int sizeS=i;

  int j=0;
  while(p[j]!='\0')
    j++;
  int sizeP=j;
  if(sizeP>sizeS){cout << "No" << endl;return 0;}

  for(int m=0;m<sizeS;m++)
    {
      for(int n=0;n<sizeP;n++)
	{
	  if(m+n<sizeS)
	    {
	  if(s[m+n]!=p[n])
	    goto retry;
	    }
	  else
	    {
	      if(s[m+n-sizeS]!=p[n])
		goto retry;
	    }
	}
      cout << "Yes" <<endl;
      return 0;
    retry:
      ;
    }
  cout << "No" << endl;

  return 0;
}