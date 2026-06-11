#include<bits/stdc++.h>
#define LL long long
using namespace std;

LL k,maxx=9;

void bfs(){
	queue<pair<LL,LL> > q;
	q.push(make_pair(1ll,1ll));
	q.push(make_pair(2ll,2ll));
	q.push(make_pair(3ll,3ll));
    q.push(make_pair(4ll,4ll));
    q.push(make_pair(5ll,5ll));
    q.push(make_pair(6ll,6ll));
    q.push(make_pair(7ll,7ll));
    q.push(make_pair(8ll,8ll));
    q.push(make_pair(9ll,9ll));
    while(!q.empty()){
    	LL djl=q.front().first;
		LL nums=q.front().second;
    	q.pop();
    	if (nums==k){
    		cout<<djl<<endl;
    		exit(0);
		}
    	if ((djl%10)-1>-1){
    		maxx++;
			q.push(make_pair(djl*10+(djl%10)-1,maxx));
		} 
    	maxx++;
		q.push(make_pair(djl*10+(djl%10),maxx));
		if ((djl%10)+1<10){
    		maxx++;
			q.push(make_pair(djl*10+(djl%10)+1,maxx));
		} 
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>k;
	bfs();
	return 0;
} 