#include<bits/stdc++.h>
using namespace std;
#define MAX 1003
int size[MAX];
int root (int Arr[ ] ,int i)
{
    while(Arr[ i ] != i)
    {
        Arr[ i ] = Arr[ Arr[ i ] ] ; 
		i = Arr[ i ]; 
    }
	return i;
}
void initialize( int Arr[ ],int size[],int N)
{
    for(int i = 0;i<N;i++)
    {
		Arr[ i ] = i ;
		size[ i ] = 1;
	}
}
void weighted_union(int Arr[ ],int size[ ],int A,int B)		
{
    int root_A = root(Arr,A);	
	/*modified union function where we connect the elements by changing the root of one of the element */
    int root_B = root(Arr,B);
    if(size[root_A] < size[root_B ])
    {
		Arr[ root_A ] = Arr[root_B];
		size[root_B] += size[root_A];
	}
    else
    {
		Arr[ root_B ] = Arr[root_A];
		size[root_A] += size[root_B];
	}
}
bool find(int Arr[],int A,int B)
{
    if( root(Arr,A)==root(Arr,B) )       //if A and B have same root,means they are connected.
    return true;
    else
    return false;
}
int main(){
	int n,q;
	cin>>n>>q;
	int a[n],s[n];
	initialize(a,s,n);
	while(q--){
		int l,u,v;
		cin>>l>>u>>v;
		if(l==0){
			weighted_union(a,s,u,v);
		}
		else{
			cout<<find(a,u,v)<<endl;
		}
	}
}