#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>

#define llong long long
#define rep(i,l,n) for(llong (i)=(l);(i)<(n);(i++))
#define _min(a,b) ((a)<(b)?(a):(b))
#define _max(a,b) ((a)>(b)?(a):(b))
#define _abs(a) ((a)>0?(a):(-(a)))

using namespace std;

int main(){
	int N;
	cin >> N;
	int count = 0;
	rep(i,0,N){
		int a,b;
		cin >> a >> b;
		if( a==b ){
			count++;
		}else{
			count = 0;
		}
		if( count==3 ){
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
}
