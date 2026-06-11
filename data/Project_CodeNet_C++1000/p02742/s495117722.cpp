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
	ll h,w;
	cin>>h>>w;
	if(w==1||h==1){
		cout<<"1"<<endl;
	}
	else{
		if((h*w)%2==0){
			cout<<(h*w)/2<<endl;
		}
		else{
			cout<<(h*w)/2+1<<endl;
		}
	}

}