#include <iostream>
#include <vector>

using namespace std;
#define ll long long

int main(){
	int h,a;
	cin>>h>>a;
	cout<< ((h%a==0)?h/a:(h/a)+1);

}