#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define FORR(i,a,b) for (int i=a; i>=b; i--)

typedef long long ll;

int main(void){
	string str;

	while(getline(cin,str)){
		if (str.size()==1 && str[0]=='.') break;
		bool f=1;
		stack<int> st;
		REP(i,str.length()){
			switch(str[i]){
				case '(' :
					st.push(0);
					break;
				case '[' :
					st.push(1);
					break;
				case ')' :
					if (st.empty()){
						f=0;
						break;
					}
					if (st.top()==0)
						st.pop();
					else
						f=0;
					break;
				case ']' :
					if (st.empty()){
						f=0;
						break;
					}
					if (st.top()==1)
						st.pop();
					else
						f=0;
					break;
			}
		}
		if (!st.empty())
			f=0;

		if (f)
			cout << "yes" << endl;
		else 
			cout << "no" << endl;
	}
	

	return 0;
}