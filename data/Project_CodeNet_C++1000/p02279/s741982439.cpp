#include<bits/stdc++.h>
using namespace std;
struct Node{
	   int father,left,right,child;
};
struct Node T[100001];
int n,k,id,x;
int getdepth(Node u){
	int d=0;
	while (u.father!=-1){
		  u=T[u.father];
		  d++;
	}
	return d;
}
string check(Node u){
	   if (u.father==-1)
	      return "root";
	   if (u.child==0)
	      return "leaf";
	   return "internal node";
}
void print(Node u){
	 int c;
	 c=u.left;
	 cout<<c;
	 while (c!=-1){
	 	   c=T[c].right;
	 	   if (c!=-1)
	 	   	  cout<<", "<<c;
	 }
}
int main(){
    cin>>n;
    for (int i=0; i<n; i++){
    	T[i].father=T[i].left=T[i].right=-1; 
	}
    int l;
	for (int i=0; i<n; i++){
		cin>>id>>k;
		if (k==0) continue;
		T[id].child=k;
	    cin>>T[id].left;
	    l=T[id].left;
	    T[T[id].left].father=id;
	    k--;
		int tt=0;
		while (k--){
			  cin>>x;
			  T[x].father=id;
			  T[l].right=x;
			  l=x;
		}
	}
	int xx;
	for (int i=0; i<n; i++){
		cout<<"node "<<i<<":"<<" parent = "<<T[i].father<<", depth = "<<getdepth(T[i])<<", "<<check(T[i])<<", ";
		if (T[i].child==0)
		   cout<<"[]"<<endl;
		else{
			cout<<"[";
			print(T[i]);
			cout<<"]"<<endl;
		}
		
	}	
	return 0;
}
