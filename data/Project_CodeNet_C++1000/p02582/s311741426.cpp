#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int N;
int Ans;
char S[99];
int main()
{
  scanf("%s", S);
  for(int I=0;I<strlen(S);I++)
  {
  	N=0;
    for(int J=I;J<strlen(S);J++)
    {
 	  	if(S[J]!='R')
 	  	{
 	  		break;
		}
		N++;
    }
    if(N>Ans)
    {
    	Ans=N;
	}
  }
  printf("%d", Ans);
  return 0;
}