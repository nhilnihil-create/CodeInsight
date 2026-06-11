#include <iostream> 
#include <string> 
#include <vector> 
#include <cmath> 
#include <algorithm> 
#include <cstdlib> 
#include <ctime> 
#include <cstdio> 
#include <functional> 
#include <set> 
#include <sstream> 


using namespace std; 

#define make_pair MP

int main(){

	int N;

	//左，下，右，上
	const int dx[]={-1,0,1,0};
	const int dy[]={0,1,0,-1};

	while(cin>>N,N){

		vector<int> x(N),y(N);
		int left=0,right=0,top=0,bottom=0;


		x[0]=y[0]=0;

		for(int i=1;i<N;i++){
			int n,d;
			cin>>n>>d;

			x[i]=x[n]+dx[d];
			y[i]=y[n]+dy[d];

			left=min(left,x[i]);
			right=max(right,x[i]);
			top=min(top,y[i]);
			bottom=max(bottom,y[i]);
		}

		cout<<right-left+1<<" "<<bottom-top+1<<endl;

	}

	return 0;
}