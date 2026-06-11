#include<iostream>
#include<vector>
#include<algorithm>
#include <cassert>
#include<set>
#include <numeric>
using namespace std;

typedef long long int ll;

ll gcd(ll x,ll y){
    if(x<y) swap(x,y);
    //xの方が常に大きい
    ll r;
    while(y>0){
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}

//オーバフローしないようにかける順番を気を付ける
ll lcm(ll x,ll y){
    return ll(x/gcd(x,y))*y;
}

set<int> getFactor(int n){
	int nn = n;
	set<int> res;
	for(int i=2;i*i<=nn;++i){
		while(n%i==0){
			res.insert(i);
			n /= i;
		}
	}
	if(n != 1) res.insert(n);
	
	return res;
}

int main(){
	int n;
	cin >> n;
	vector<int> data(n);
	for(int i=0;i<n;++i){
		cin >>data[i];
	}
	set<int> re;
	bool isPairWise = true;
	for(int i=data.size()-1;isPairWise && i>=0;--i){
		set<int> se = getFactor(data[i]);
		for(int a : se){
			//cout << a << endl;
			if(re.find(a) != re.end()){
				isPairWise = false;
				break;
			}
			re.insert(a);
		}
	}
	if(isPairWise){
		cout << "pairwise coprime" <<endl;
		return 0;
	}
	
	int tmp = data[0];
	for(int i=1;i<n;++i){
		tmp = gcd(tmp,data[i]);
	}
	
	if(tmp == 1){
		cout << "setwise coprime" <<endl;
	}else{
		cout << "not coprime" << endl;
	}
	
	return 0;
}
