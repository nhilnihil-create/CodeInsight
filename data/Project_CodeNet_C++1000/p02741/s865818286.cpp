#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <istream>
#include <sstream>
#include <cctype>
#include <iomanip>
//cout << fixed << setprecision(20) << *** << endl;
#define rep(i,N) for(int i=0;i<(int)N;++i)
typedef long long ll;
using namespace std;
int main()
{
	ll K;
	cin>>K;
	if(K==4||K==6||K==9||K==10||K==14||
		K==21||K==22||K==25||K==26){
		cout<<"2"<<endl;
	}
	else if(K==8||K==12||K==18||K==20||K==27){
		cout<<"5"<<endl;
	}
	else if(K==16){
		cout<<"14"<<endl;
	}
	else if(K==24){
		cout<<"15"<<endl;
	}
	else if(K==28||K==30){
		cout<<"4"<<endl;
	}
	else if(K==32){
		cout<<"51"<<endl;
	}
	else{
		cout<<"1"<<endl;
	}
}