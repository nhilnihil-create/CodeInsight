#include <cstdio>
#include <utility>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#define REP(i,n) for(int i=0;i<n;i++)
typedef long long ll;
using namespace std;
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef vector<string> vs;

int main() 
{

	while(true)
	{
		string s;
		getline(cin,s);
		if(s=="."){break;}
		
		//かっこ以外を消去
		int i=0;
		while(i<s.length()){
			if(s[i]!='[' && s[i]!=']' && s[i]!='(' && s[i]!=')')
			{	s.erase(s.begin() + i); i--;}
			i++;}
		
		int x = s.length()/2;
		REP(i,x)
		{
			REP(i,s.length()-1)
			{
				if(	(s[i]=='[' && s[i+1]==']') || (s[i]=='(' && s[i+1]==')')	)
				{s.erase(s.begin()+i);
				s.erase(s.begin()+i);
				break;}
			}
		}
		if(s.length()==0)cout << "yes" <<endl;
		else cout << "no" << endl;
	}
	return 0;
}