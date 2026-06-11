#include <iostream>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)

int main(){
	int n,m,p;
	while(cin >>n >>m >>p,n!=0){
		int tmp, set;
		int sum=0;
		rep(i,n){
			cin >> tmp;
			sum+=tmp;
			if(i==m-1) set = tmp;
		}
		if(set == 0){
			cout << 0 << endl;
		}else{
			sum = (sum * 100 - (sum * p));
			cout << (sum/set) << endl;
		}
	}
}