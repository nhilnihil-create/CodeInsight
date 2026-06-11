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
	string S;
	cin>>S;
	rep(i,S.size()-1){
		if(S[i]=='P'&&S[i+1]=='?'){
			S[i+1]='D';
		}
		else if(S[i]=='?'&&S[i+1]=='?'){
			S[i]='P';
			S[i+1]='D';
		}
		else if(S[i]=='?'&&S[i+1]=='D'){
			S[i]='P';
		}
		else if(S[i]=='?'&&S[i+1]=='P'){
			S[i]='D';
		}
	}
	if(S.back()=='?'){
		S.back()='D';
	}
	cout<<S<<endl;
}