#include <iostream>
#include <cstring>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>
#include <string>
#include <iterator>
#include <vector>
 
using namespace std;

typedef long long ll;
typedef long double ld;
#define L(ID) ((ID*2)+1)
#define R(ID) ((ID*2)+2)
#define M(L,R) ((L+R)/2)
#define forr(start,end) for(int i = start; i < end; i++)
#define gap ' '
 
const int MAXN = 26;

int largest(int a, int b){
	return (a<b)?b:a;
}


int main() {
	int a,b;
	cin >> a >> b;
	if((a+b)%2){
		cout << "IMPOSSIBLE" << endl;
	}
	else{
		cout << (a+b)/2 << endl;
	}






    return 0;
}