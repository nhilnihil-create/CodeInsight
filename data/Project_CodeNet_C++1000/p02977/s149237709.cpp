#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <bitset>     //UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
#include <cassert>
#include <iomanip>        //do setprecision
#include <ctime>
#include <complex>
using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)

#define ST first
#define ND second
#define PB push_back
#define PF push_front
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double
#define pii pair<int,int>
#define pll pair<LL,LL>
#define vi vector<int>
#define vii vector<vi>

const double pi = 3.14159265358979323846264;
const int mod=1000000007;

int main(){
	 //cin.tie(0);
	//ios::sync_with_stdio(false);
	//std::cout << std::fixed;
	//std::cout << std::setprecision(12);
	//std::cout << std::defaultfloat;
	int n;
	cin>>n;
	if(n==3){
		cout<<"Yes"<<endl;
		cout<<1<<" "<<2<<endl;
		cout<<3<<" "<<2<<endl;
		cout<<3<<" "<<4<<endl;
		cout<<5<<" "<<4<<endl;
		cout<<5<<" "<<6<<endl;
		return 0;
	}
	FOR(i,0,20){
		if(n==(1<<i)){
			cout<<"No"<<endl;
			return 0;
		}
		if((n>>i)==0){
			cout<<"Yes"<<endl;
			int d=1<<(i-1);
			FOR(i,1,d-1){
				cout<<i<<" "<<i+1<<endl;
			}
			cout<<d-1<<" "<<n+1<<endl;
			FOR(i,1,d-1){
				cout<<i+n<<" "<<i+n+1<<endl;
			}
			if(n<=d+1){
				cout<<d<<" "<<d+1<<endl;
				cout<<1<<" "<<d+1<<endl;
				cout<<d+n<<" "<<d+1+n<<endl;
				cout<<d+n<<" "<<1<<endl;
				return 0;
			}
			if(n==d+2&&d>=4){
				cout<<d<<" "<<d+1<<endl;
				cout<<1<<" "<<d+1<<endl;
				cout<<d+n<<" "<<d+1+n<<endl;
				cout<<d+n<<" "<<1<<endl;
				cout<<d+2<<" "<<d+1<<endl;
				cout<<2<<" "<<d+2+n<<endl;
				return 0;
			}
			FOR(i,d+2,n+1){
				if(i==n){
					cout<<d<<" "<<d+1<<endl;
					cout<<i-d-2<<" "<<d+1<<endl;
					cout<<d+n<<" "<<d+1+n<<endl;
					cout<<d+n<<" "<<i-d-1<<endl;
					cout<<i-d<<" "<<i<<endl;
					cout<<d+1<<" "<<i+n<<endl;
				}else{
					cout<<i+1<<" "<<1<<endl;
					cout<<i+1<<" "<<i<<endl;
					cout<<i+n<<" "<<1<<endl;
					cout<<i+n+1<<" "<<i+n<<endl;
				}
				if(i+1==n){//偶数終わり
					cout<<d<<" "<<d+1<<endl;
					cout<<1<<" "<<d+1<<endl;
					cout<<d+n<<" "<<d+1+n<<endl;
					cout<<d+n<<" "<<1<<endl;
				}
				i+=1;
			}


			return 0;
		}
	}



	return 0;
}
