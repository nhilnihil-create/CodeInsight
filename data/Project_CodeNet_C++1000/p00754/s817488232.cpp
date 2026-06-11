#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <functional>
#include <set>
#include <sstream>
#include <map>
#include <queue>

using namespace std;
 
const double eps=1e-10;

const int dy[]={-1,-1,0,1,1, 1, 0,-1};
const int dx[]={ 0, 1,1,1,0,-1,-1,-1};

int main()
{

	string s;
	while(getline(cin,s),s!="."){
		for(int i=s.size()-1;i>=0;i--){
			if(s[i]!='(' && s[i]!=')' && s[i]!='[' && s[i]!=']') s.erase(s.begin()+i);
		}

		int pos1,pos2;
		while( (pos1=s.find("()"))!=string::npos ||  (pos2=s.find("[]"))!=string::npos){

			if(pos1!=string::npos){
				s.replace(pos1,2,"");
				continue;
			}

			if(pos2!=string::npos){
				s.replace(pos2,2,"");
				continue;
			}


		}

		if(s=="") cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}

	return 0;
}