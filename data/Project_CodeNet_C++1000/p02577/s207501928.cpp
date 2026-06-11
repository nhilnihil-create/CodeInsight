#include<iostream>
#include<cstring>

using namespace std;
 
int main()
{
  char N[1000000];

  cin >> N;

  int sum = 0;
  int len = strlen(N);

  for(int i=0;i<len;i++)
    sum+=N[i]-'0';

  if((sum%9)==0)
    cout << "Yes";
  else
    cout << "No";
}

      