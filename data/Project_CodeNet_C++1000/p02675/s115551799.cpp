#include<iostream>
using namespace std;
int main()
{
    // 整数の入力
    int n;
    cin >> n;
    n = n%100;
    n = n%10;
    if(n==2 || n==4 || (n>=5 && n%2==1) )
      cout << "hon" << endl;
    else if( n==1 || n%2==0)
      cout << "pon" << endl;
    else
      cout << "bon" << endl;
    return 0;
}