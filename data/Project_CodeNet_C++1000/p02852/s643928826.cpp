#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 100005

int N,M;
int min_dist[SIZE];
vector<int> ANS;
char buf[SIZE];




int main(){

	scanf("%d %d",&N,&M);
	scanf("%s",buf);

	vector<int> V;

	for(int i = 0; i <= N; i++){
		if(buf[i] == '0'){

			V.push_back(i);
		}
	}

	stack<int> S;

	S.push(N);

	int left,right,mid;
	int pre = V.size()-1,next;

	while(pre > 0){

		left = 0,right = pre-1,mid = (left+right)/2;
		next = -1;

		while(left <= right){

			if(V[pre]-V[mid] <= M){

				next = mid;
				right = mid-1; //より左へ
			}else{

				left = mid+1;
			}
			mid = (left+right)/2;
		}
		if(next == -1){

			printf("-1\n");
			return 0;
		}
		S.push(V[next]);
		pre = next;
	}

	int loc = S.top();
	S.pop();
	printf("%d",S.top()-loc);
	loc = S.top();
	S.pop();

	while(!S.empty()){

		printf(" %d",S.top()-loc);
		loc = S.top();
		S.pop();

		if(S.empty())break;
	}

	return 0;
}
