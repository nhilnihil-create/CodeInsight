#include <iostream>
using namespace std;

int main()
{
 bool flag1 = true ;
 bool flag2 = true ;
 int N;
 cin >> N ;
 int arr[N];
 for (int i=0 ; i<N ; i++)
    cin >> arr[i];
 int counter = 0 ;
 for (int i=1 ; i<=N ; i++)
    {
      if (i%2 == 0)
        flag1=false ;
      else if (arr[i-1]%2 == 0)
        flag2 = false ;
      if (flag1 && flag2)
        counter++ ;
        flag1 = true ;
        flag2 = true ;

    }
      cout << counter << endl ;
}
