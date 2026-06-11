

#include <iostream>

using namespace std;

int main()
{
  int N,cou=0;
 cin >> N ;
 int arr[N];
 for(int i = 0; i < N; i++) 
 cin >> arr[i];
  for(int i = 0; i < N; i++) {
     // cout << i+1 << " "<< arr[i];
      if (arr[i]%2!=0&&(i+1)%2!=0)
      cou++;
  }
  cout << cou << endl;

    return 0;
}
