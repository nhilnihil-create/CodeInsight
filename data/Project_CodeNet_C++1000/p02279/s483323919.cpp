#include<iostream>
using namespace std;
const int null=-1;

struct Node{
	int parent;
	int child;
	int sibling;
	int depth;
	int degree;
};
Node *nodes;

/*
int rootSearch(Node *nodes, int n){
	for( int i=0;;i++ ){
		if( nodes[i].parent==null ){
			return i;
		}
	}
}
*/
int traceRoot(Node *nodes, int id){
	if(nodes[id].parent==null) return id;
	else return traceRoot(nodes, nodes[id].parent);
}

int rootSearch(Node *nodes, int n){
	int start;
	for( int i=0;; i++ ){ 
		if( nodes[i].parent==null ) return i;
		else start=i;
	}
	return traceRoot(nodes, start);
}
		


void setDepth( Node *nodes, int id, int d ){
	nodes[id].depth=d;
//	cout<<"d : "<<d;
//	cout<<"id.child"<<nodes[id].child<<endl;
//	cout<<"id.parent"<<nodes[id].parent<<endl;
	if( nodes[id].sibling !=null ){
		setDepth( nodes, nodes[id].sibling, d );
	}
	if( nodes[id].child !=null ){
		setDepth( nodes, nodes[id].child, d+1 );
	}
	
}

void show(Node *nodes, int n){
	for( int id=0; id<n; id++ ){
		cout<<"node "<<id<<": "
			<<"parent = "<<nodes[id].parent<<", "
			<<"depth = "<<nodes[id].depth<<", ";
		if( nodes[id].parent==null ) cout<<"root, ";
		else if( nodes[id].child==null ) cout<<"leaf, ";
		else cout<<"internal node, ";

		cout<<"[";
		if( nodes[id].child !=null ){
			int tp=nodes[id].child;
			cout<<tp;
			for( int i=1; i<nodes[id].degree; i++ ){
				tp=nodes[tp].sibling;
				cout<<", "<<tp;
			}
		}
		cout<<"]"<<endl;

	}
}

int main()
{
	int n;cin>>n;
	nodes=new Node[n];

	for( int i=0; i<n; i++ ) nodes[i].parent=nodes[i].child=nodes[i].sibling=null;

	int root;	
	for( int i=0, id, deg, cld, prevcld; i<n; i++ ){
		cin>>id>>deg;
		nodes[id].degree=deg;
		
		if( deg>0 ){
			for( int j=0; j<deg; j++ ){ //??????????????????.
				cin>>cld;
				nodes[cld].parent=id; //?????????????????????????????????????????????
				
				if( j==0 ){
					nodes[id].child=cld; //????????????????????????????????????
				}else{
					nodes[prevcld].sibling=cld; //??????????????????????????????
				}
				prevcld=cld;
			}

		}
	//	if( nodes[id].parent==null ) root=id; //root???????????????????????????????????????
	}

	root=rootSearch(nodes, n);
	setDepth(nodes, root, 0);
	show(nodes, n);
}


		