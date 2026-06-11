#include<iostream>
using namespace std;
int main()
{
  int x;
  int y;
  int z;
  cin >> x;
  cin >> y;
  cin >> z;
  
  if ((x == y) && (y == z))
    cout <<"No";
  else
    if ((x == y)||(y == z)||(x == z))
        cout <<"Yes";
    else 
        cout <<"No";
}