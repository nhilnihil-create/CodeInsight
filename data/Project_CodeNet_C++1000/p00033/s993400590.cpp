#include<iostream>
using namespace std;

int D, A[10];
const int MAX_DATA = 100000;
bool owata[MAX_DATA];

bool dfs(int n,int a,int b)
{
	if(n==10)
	{
		return true;
	}

	if(A[n]>a){
	if(dfs(n+1,A[n],b))
	{
		return true;
	}
	}

	if(A[n]>b){
	if(dfs(n+1,a,A[n]))
	{
		return true;
	}
	}

	return false;

}

int main(){
	cin>>D;
	for(int i=1;i<=D;i++){
		for(int j=0;j<10;j++){
			cin>>A[j];
		}

		owata[i] = dfs(0, 0, 0);
	}
	for(int i=1;i<=D;i++)
	{
		cout << (owata[i] ? "YES":"NO") << endl;
	}
}