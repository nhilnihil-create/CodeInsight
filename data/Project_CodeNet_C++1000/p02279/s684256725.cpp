#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define loop(i,a,b) for(i=a;i<b;i++)
#define rloop(i,a,b) for(i=a;i>=b;i--)
#define vi vector<int>
#define vs vector<string>
typedef pair<string,int> card;
#define mark first
#define kazu second
const int inf=1e9+1;
const ll INF=1e16;
#define MOD 1000000007
#define mod 1000000009
#define pi 3.14159265358979323846

class Tree{
	int node;
	int degree;
	int parent;
	int depth;
	string type;
	vi children;
public:
	Tree(){}
	int get_node() const{return node;}
	void set_node(int a){node=a;}
	int get_degree() const{return degree;}
	void set_degree(int a){degree=a;}
	int get_parent() const{return parent;}
	void set_parent(int a){parent=a;}
	int get_depth() const{return depth;}
	void set_depth(int a){depth=a;}
	string get_type() const{return type;}
	void set_type(string s){type=s;}
	int get_children(int i) const{return children[i];}
	void set_children(int a){children.push_back(a);}
};

void depth(vector<Tree> &tree,int i);

int main(){
	int n,i,j;
	cin>>n;
	vector<Tree> tree(n);
	loop(i,0,n){
		tree[i].set_node(i);
		tree[i].set_parent(-1);
		tree[i].set_depth(-1);
	}
	int id,k,c;
	loop(i,0,n){
		cin>>id>>k;
		tree[id].set_degree(k);
		loop(j,0,k){
			cin>>c;
			tree[id].set_children(c);
			tree[c].set_parent(id);
		}
	}
	loop(i,0,n){
		if(tree[i].get_parent()==-1){
			tree[i].set_depth(0);
			tree[i].set_type("root");
			break;
		}
	}
	depth(tree,i);
	loop(i,0,n){
		cout<<"node "<<tree[i].get_node()<<": parent = "<<tree[i].get_parent();
		cout<<", depth = "<<tree[i].get_depth()<<", "<<tree[i].get_type()<<", [";
		loop(j,0,tree[i].get_degree()-1){
			cout<<tree[i].get_children(j)<<", ";
		}
		if(tree[i].get_degree()!=0){
			cout<<tree[i].get_children(tree[i].get_degree()-1);
		}
		cout<<"]"<<endl;
	}
}
void depth(vector<Tree> &tree,int i){
	int j;
	loop(j,0,tree[i].get_degree()){
		tree[tree[i].get_children(j)].set_depth(tree[i].get_depth()+1);
		}
	if(tree[i].get_degree()==0){
		if(tree[i].get_type()!="root"){
			tree[i].set_type("leaf");
		}
	}else{
		if(tree[i].get_type()!="root"){
			tree[i].set_type("internal node");
		}
		loop(j,0,tree[i].get_degree()){
			depth(tree,tree[i].get_children(j));
		}
	}
}
	