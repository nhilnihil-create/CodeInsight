#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
	struct node *parent,*left,*right;
	int id,depth;
};
node* nil;
void setdepth(node*,int);
node* getroot(node*);
void printchildren(node*);

int main(){
	int n;
	cin >> n;
	node **N;
	nil = (node*)malloc(sizeof(node));
	N = (node**)malloc(sizeof(node*)*n);
	for(int i=0;i<n;i++) N[i] = (node*)malloc(sizeof(node));
	nil->parent = nil->left = nil->right = nil;
	//cerr << "error01" << endl;
	
	nil -> id = -1;
	N[0]->parent = nil;
	//cerr << "error02" << endl;
	for(int i=0;i<n;i++) N[i]->parent = N[i]->left = N[i]->right = nil;
	//cerr << "error03" << endl;	
	for(int i=0;i<n;i++){
		int id,k;
		cin >> id >> k;
		N[id]->id = id;
		int *c;
		//cerr << "error04" << endl;	
		c = (int*)malloc(sizeof(int)*k);
		for(int j=0;j<k;j++) cin >> c[j];
		//cerr << "error05" << endl;	
		for(int j=0;j<k;j++){
			if(j ==0) N[id]->left = N[c[j]];
			N[c[j]]->parent = N[id];
			//cerr << "error06 " << i << endl;	
			if(j < k-1) N[c[j]]->right = N[c[j+1]];
			else if(j == k-1) N[c[j]]->right = nil;
		}
		if(k == 0) N[id]->left = nil;
		free(c);
	}
	//cerr << "error7" << endl;
	node *root = getroot(N[0]);
	//cerr << "error8" << endl;
	setdepth(root,0);
	//cerr << "error9" << endl;
	for(int i=0;i<n;i++){
		int p,d;
		p = N[i]->parent->id;
		d = N[i] -> depth;
		cout << "node " << N[i]->id << ": parent = " << p << ", depth = " << d << ", ";
		if(N[i] == root) cout << "root, ";
		else if(N[i]->left == nil) cout << "leaf, ";
		else cout << "internal node, ";
		printchildren(N[i]);
		cout << endl; 
	}
	free(nil);
	for(int i=0;i<n;i++) free(N[i]);
	free(N);
	return 0;

}

void setdepth(node* x,int d){
	//cerr << "node:" << x->id << " depth:" << d << endl;
	x->depth = d;
	if(x->right != nil) setdepth(x->right,d);
	if(x->left != nil) setdepth(x->left,d+1);
}

node* getroot(node* x){
	int i=0;
	while(x->parent != nil){
		x = x->parent;
		i++;
		if(i >= 100000){
			//cerr << "ERROR:GETROOT" << endl;
		}
	}
	//cerr << "root: " << x->id << endl;
	return x;
}

void printchildren(node* x){
	node* l = x->left;
	cout << "[";
	while(1){
		if(l != nil)cout << l->id;
		if(l->right == nil) break;
		else cout << ", ";
		l = l->right;
	}
	cout << "]";
}