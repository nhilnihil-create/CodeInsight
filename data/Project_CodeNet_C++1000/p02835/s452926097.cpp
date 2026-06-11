#include<iostream>
using namespace std;
int main()
{
    // スペース区切りの整数の入力
    int a, b, c;
    cin >> a >> b >> c;
  
  	int result = a + b + c;
  	if (result > 21) {
      cout << "bust" << endl;
    } else {
      cout << "win" << endl;
    }
    return 0;
}