#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const long mod=1e9+7;
const int siz=2e5;
const long inf=1e9;
int main(){
	int N; cin>>N;
	int S[(1<<N)];
	rep(i,0,(1<<N)) cin>>S[i];
	sort(S, S+(1<<N), greater<int>());
    int res[(1<<N)] = {}; res[0] = S[0];
	priority_queue<pair<int,int>> pq[N]; pq[N-1].push({res[0], 0});
	int k = 1;
	rep(i,1,(1<<N)){
        int j = N-1;
        int v;
        while(j >= 0){
            if(!pq[j].empty()){
                v = pq[j].top().second;
        		if(res[v] > S[k]){
                    res[v|(1<<j)] = S[k];
                    pq[j].pop();
                    break;
                }
            }
            if(j == 0){ cout<<"No"<<endl; return 0; }
            j--;
        }
        if(j > 0){
            pq[j-1].push({res[v], v});
        	pq[j-1].push({res[v|(1<<j)], v|(1<<j)});
        }k++;
	}cout<<"Yes"<<endl;
}