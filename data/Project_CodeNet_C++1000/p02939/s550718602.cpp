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
	ll ANS=0;
	string s;
	char ch='#';
	cin>>s;
	for(ll i=0;i<s.size();i++){
		if(s[i]==ch){
			if(i!=s.size()-1){
				i++;
				ANS++;
				ch='#';
			}
		}
		else{
			ANS++;
			ch=s[i];
		}
		//cout<<ANS<<":"<<i<<endl;
	}
	cout<<ANS<<endl;
}