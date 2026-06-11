#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	while(getline(cin, str)){
		if(str[0] == '.' && str.size() == 1)
			break;
		string tmp = "";
		for(unsigned i=0;i<str.size();i++){
			if(str[i] == '(' || str[i] == ')' || str[i] == '[' || str[i] == ']'){
				unsigned a = tmp.size();
				if(a!=0) a--;
				if((tmp[a] == '(' && str[i] == ')' )||(tmp[a] == '[' && str[i] == ']'))
					tmp.erase(a);
				else
					tmp += str[i];
			}
		}
		if(tmp.size()==0)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}