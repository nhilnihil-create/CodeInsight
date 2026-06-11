#include<iostream>
using namespace std;

int prime(int n) {
	int i;

	if (n <= 1)/*1以下の場合は0を返す*/
	{
		return 0;/*素数ではない*/
	}
	/*nまでの数値を繰り返し、余りがあれば0を返す*/
	for (i = 2; i < n; i++) {
		if (n % i == 0) {
			return 0;/*素数ではない*/
		}
	}

	return 1;/*素数である*/
}

int main(){
  int x;
  cin>>x;
  int i=0;
  while(1){
    if (prime(x+i)==1){
      cout<<x+i<<endl;
      break;
    }
    else i++;
  }
}