#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
#include <vector>
#include <stack>
using namespace std;

//常に心してかかれ
//簡単なことを簡単にできるように練習する

	int n;
	int A[20+1];
	int q;
	int m[200+1];
//模範解答
bool solve(int i,int m){//solve(i,m):A[i]?A[n-1]でmが作れるかどうか
	bool res;
	if(m == 0)
		return true;
	if(i >= n)
		return false;
	res = solve(i+1,m) || solve(i+1,m-A[i]);
	return res;
}

int main(){
	scanf("%d",&n);
	//printf("%d\n",n);//確認用
	for(int i=0;i<n;i++){
		scanf("%d",&A[i]);
		//printf("%d ",A[i]);//確認用
	}
	//printf("\n");//確認用
	scanf("%d",&q);
	//printf("%d\n",q);//確認用
	for(int i=0;i<q;i++){
		scanf("%d",&m[i]);
		//printf("%d ",m[i]);//確認用
	}

	for(int i=0;i<q;i++){
		if(solve(0,m[i]))
			cout <<"yes" <<endl;
		else 
			cout <<"no" <<endl;
	}

	return 0;
}