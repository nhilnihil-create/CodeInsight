#include<iostream>
using namespace std;

int noi(int *N,int *D)
{
  int val=2*(*D)+1;
  float num=(*N)/val;

  if((val*num)==*N)
    return num;
  else
    return num+1;

}

int main()
{
    int N;
    int D;
    scanf("%d %d",&N,&D);
    printf("%d",noi(&N,&D));
}
