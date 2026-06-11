#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
#define MAX 10000
#define TOSEC(h,m,s) ((h)*3600+(m)*60+(s))
struct Train{
	int st;
	int ed;
	bool operator<(const Train &t)const{
		return ed > t.ed;
	}
};
bool CompTrainForSort(const Train &a, const Train &b){
	return a.st < b.st;
}
int main(){
	/*priority_queue<int> test;
	test.push( 100 );
test.push( 101 );
test.push( 102 );
test.push( 103 );
test.push( 10 );
test.push( 49 );

cout << test.top() << endl;*/

	while(true){
		Train vt[MAX];
		unsigned int ans = 0;
		int n;
		priority_queue< Train > pq;
		scanf("%d", &n);

		if( n == 0 ) break;

		for(int i = 0; i < n; ++i){
			int sh,sm,ss;
			int eh,em,es;
			Train t;
			
			scanf("%02d:%02d:%02d %02d:%02d:%02d",
				&sh,&sm,&ss,
				&eh,&em,&es);
			t.st = TOSEC(sh,sm,ss);
			t.ed = TOSEC(eh,em,es);

			vt[i] = t;
		}

		sort( vt, vt + n, CompTrainForSort );
		
		for(int i = 0; i < n; ++i){
			if( pq.size() == 0 )
				pq.push( vt[i] );
			else{
				Train tt = pq.top();
				if( tt.ed <= vt[i].st ){
					pq.pop();
					pq.push( vt[i] );
				}else{
					pq.push( vt[i] );
				}
			}
			ans = max(ans, pq.size());
		}
		printf("%d\n", ans);
	}
	return 0;
}