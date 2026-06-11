#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
class tree{
	public:
	int id;
	int parent;
	int depth;
	vector<int> next;
}data[100000];

void decidedepth(int dep,int i){
	data[i].depth=dep;
	for(vector<int>::iterator j=data[i].next.begin();
								j!=data[i].next.end();j++){
		decidedepth(dep+1,*j);
	}
}

int main(){
	cin>>n;
	int no,k,c;
	for(int i=0;i<n;i++)	data[i].parent=-1;
	for(int i=0;i<n;i++){
		cin>>no>>k;
		data[no].id=no;
		for(int j=0;j<k;j++){
			cin>>c;
			data[no].next.push_back(c);
			data[c].parent=no;
		}
	}
	for(int i=0;i<n;i++){
		if(data[i].parent==-1){
			decidedepth(0,i);
			break;
		}
	}
	for(int i=0;i<n;i++){
		cout<<"node "<<data[i].id<<": parent = "<<data[i].parent;
		cout<<", depth = "<<data[i].depth<<", ";
		if(data[i].parent==-1)	cout<<"root, ";
		else if(data[i].next.empty())	cout<<"leaf, ";
		else 	cout<<"internal node, ";
		cout<<"[";
		for(int j=0;j<(int)data[i].next.size();j++){
			if(j) 	cout<<", ";
			cout<<data[i].next[j];
		}
		cout<<"]\n";
	}
	return 0;
}