
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1173&lang=jp

#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
#include<ctime>
#include<cstring>
#include<numeric>

#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define dump(a) (cerr << #a << "=" << (a) << endl)
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;

using namespace std;

int LPAR, RPAR, LBRACE, RBRACE;
bool isBalance=true;
vector<char> vec; 

void init()
{
	LPAR=0, RPAR=0, LBRACE=0, RBRACE=0;
	isBalance=true;
	vec.clear();
}

void check(char word)
{				
	if(word == '('){ LPAR++; vec.push_back(word); }
	if(word == ')')
	{
		if(vec.empty()){
			isBalance=false;
		}else{
			char tmp = vec.back();
			vec.pop_back();
			if(tmp != '('){ isBalance=false; }
			RPAR++;
		}

	}
	if(word == '['){ LBRACE++; vec.push_back(word); }
	if(word == ']')
	{
		if(vec.empty()){
			isBalance=false;
		}else{
			char tmp = vec.back();
			vec.pop_back();
			if(tmp != '['){ isBalance=false; }
			RBRACE++;
		}
	}
}

int main() {

	string line;

	while(true)
	{
		init();
		getline(cin, line);
		//dump(line); //DEBUG
		if(line == "."){ break; }

		rep(i,line.size())
		{
			check(line[i]);
			if(RPAR > LPAR){ isBalance=false; }
			if(RBRACE > LBRACE){ isBalance=false; }
			
			if(LPAR && line[i] == ')'){ LPAR--; RPAR--;}
			if(LBRACE && line[i] == ']'){ LBRACE--; RBRACE--; }
		}

		if(!LPAR && !RPAR && !LBRACE && !RBRACE)
		{
			//Do Nothing...
		}else{
			isBalance = false;
		}

		if(isBalance){
			cout << "yes" << endl;
		}else{
			cout << "no" << endl;
		}
	}

	return 0;
}