#include<iostream>
#include<vector>
#include<algorithm>
#include <cassert>
#include<set>
#include <numeric>
using namespace std;

typedef long long int ll;

int main(){
	int k;
	
	cin >> k;
	
	int res = 1;
	set<int> se;
	
	int amari = 7%k;
	int tmp = 7;
	while(amari != 0 && se.find(amari) == se.end()){
		//cout << amari <<endl;
		se.insert(amari);
		tmp = (tmp * 10) % k;
		amari = (tmp + amari) %k;
		res++;
	}
	
	if(amari == 0){
		cout << res <<endl;
	}else{
		cout << -1 <<endl;
	}
	
	return 0;
}
