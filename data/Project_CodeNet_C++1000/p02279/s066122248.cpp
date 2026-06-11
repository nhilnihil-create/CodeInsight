#include <algorithm>
#include <iostream>
#include <deque>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
string nodetype[3]={"root", "internal node", "leaf"};

struct tree{
	int parent, child, next;
};

int split(deque <int> &tokens,  string &text, char delim=' '){
	int start = 0, end = 0;
	string tmps;
	char *ends;
	tokens.clear();
	for (int i=0; i<(int)text.size(); i++)
		if (text[i] == delim){
		end = i;
		tmps = text.substr(start, end - start);
		tokens.push_back(strtol(tmps.c_str(),&ends,0));
		start = end + 1;
	}
	tmps = text.substr(start);
	tokens.push_back(strtol(tmps.c_str(),&ends,0));
	return 0;
}

int type(tree &node){
	int e;
	if (node.parent == -1) e = 0;
	else if (node.child == -1) e = 2;
	else e = 1;
	return e;
}

int depth(int e, vector <tree> &node){
	int tmp=node[e].parent, d;

	if (tmp == -1) d = 0;
	else d = depth(tmp, node) + 1;

	return d;
}

string children(int i, vector <tree> &node){
	stringstream ss;

	string str = "[";	
	int e = node[i].child;
	while (e!=-1){
		ss << e;
		if (str=="[") str +=  ss.str();
		else str += ", " + ss.str();
		ss.str("");
		e = node[e].next;
	}
	str += "]";

	return str;
}

int main(void){
	int n, e, tmp;
	string text;
	deque <int> buf;
	stringstream ss;

	cin >> n;
	getline(cin, text);
	vector <tree> node(n);

	for (int i=0; i<n; i++){
		node[i].parent = -1;
		node[i].child = -1;
		node[i].next = -1;
	}

	for (int i=0; i<n; i++){
		getline(cin, text);
		split(buf, text);

		e = buf[0];
		buf.pop_front();

		int nc= buf[0];
		buf.pop_front();

		if (nc != 0){
			for (int j=0; j<nc; j++){
				tmp = buf[j];
				if (j==0) node[e].child = tmp;
				else node[buf[j-1]].next = tmp;
				node[tmp].parent = e;
				}
		}
		buf.clear();
	}

	for (int i = 0; i<n; i++){
		ss.str("");
		ss << "node " << i <<": ";
		ss << "parent = " << node[i].parent << ", ";
		ss << "depth = " << depth(i, node) << ", ";
		e = type(node[i]);
		ss << nodetype[e] << ", ";
		ss << children(i, node);
		cout << ss.str() << endl;
	}

	return 0;
}