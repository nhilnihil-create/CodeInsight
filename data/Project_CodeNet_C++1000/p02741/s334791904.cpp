#include <iostream>
#include <array>

int main(){
	using namespace std;
  	array<int, 52> hoge = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
  	int n;
  	cin >> n;
  	cout << hoge.at(n - 1); 
}