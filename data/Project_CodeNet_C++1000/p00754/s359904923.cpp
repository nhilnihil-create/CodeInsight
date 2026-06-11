#include <vector>
#include <stack>
#include <iostream>
#include <string>

using namespace std;
int main(int argc,char **argv){
	vector<string> inputs;

	while(true){
		string line;
		getline(cin,line);
		if(line == "."){ break; }
		inputs.push_back( line );
	}

	for(auto it=inputs.begin();it!=inputs.end();++it){
		stack<char> st;
		bool isok=true;
		for(auto cit=it->begin();cit!=it->end();++cit){
			char c = *cit;
			if(c=='('||c=='['){ st.push(c); }
			else if(c==')'){
				if(st.size()==0){isok=false;break;}
				if(st.top()=='('){ st.pop(); }
				else{ isok=false; break; }
			}
			else if(c==']'){
				if(st.size()==0){isok=false;break;}
				if(st.top()=='['){ st.pop(); }
				else{ isok=false; break; }
			}
		}
		isok = isok && st.empty();
		cout << (isok?"yes":"no") << endl;
	}

}