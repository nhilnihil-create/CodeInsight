#include<iostream>

using namespace std;
struct node
{
	int p,l,r;
};
const int MAX=100005;
int D[MAX];
void print(node A[],int u){
   cout<<"node "<<u<<": ";
   cout<<"parent = "<<A[u].p<<", ";
   cout<<"depth = "<<D[u]<<", ";

   if(A[u].p==-1)cout<<"root, ";
   else if(A[u].l==-1)cout<<"leaf, ";
   else cout<<"internal node, ";
   
   cout<<"[";
   int c;
   for(int i=0,c=A[u].l;c!=-1;i++,c=A[c].r){
      if(i)cout<<", ";
   	  cout<<c;
   }
    cout<<"]"<<endl;
}
void rec(node A[],int u,int p){
    D[u]=p;
    if(A[u].r!=-1)rec(A,A[u].r,p);
    if(A[u].l!=-1)rec(A,A[u].l,p+1);

}
int main(){

	int n;
	cin>>n;
	node *A=new node[n];
	for(int i=0;i<n;i++)A[i].p=A[i].l=A[i].r=-1;
    int v,d,c,l;
	for(int i=0;i<n;i++){
		cin>>v>>d;
		for(int j=0;j<d;j++){
			cin>>c;
			
			if(j==0)A[v].l=c;
			else A[l].r=c;
			l=c;
			A[c].p=v;
		}

	}
	int r;
    for(int i=0;i<n;i++){
    	if(A[i].p==-1){  r=i;break;}
    }
    rec(A,r,0);
    
    for(int i=0;i<n;i++)print(A,i);
     
	delete A;

	return 0;
}
