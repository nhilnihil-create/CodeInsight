#include<iostream>
#include<vector>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
using namespace std;
int vector_finder(std::vector<int> vec, int number) {
	auto itr = std::find(vec.begin(), vec.end(), number);
	size_t index = std::distance(vec.begin(), itr);
	if (index != vec.size()) { // 発見できたとき
		return 1;
	}
	else { // 発見できなかったとき
		return 0;
	}
}
int main() {
  int a,b;
  cin>>a>>b;
  cout << a*b << endl;
  return 0;
}