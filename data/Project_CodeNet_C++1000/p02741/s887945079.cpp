#include<iostream>
using namespace std;

#define SIZE 32

int main()
{
  int seq[] = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
  int inp = 0;
  cin >> inp;
  cout << seq[inp-1] << endl;
  
  return 0;
}