#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<math.h>


#define CI cin >>
#define CO cout <<
#define E << endl;

using namespace std;


int main(void) {
	int num = 0;
	vector<int>array;
	int temp = 0;

	CI num;

	for (int i = 0; i < num; ++i) {
		CI temp;
		array.push_back(temp);
	}
	
	for (int i = num - 1; i > 0; --i) {
		CO array[i] << " ";
	}

	CO array[0] E

}