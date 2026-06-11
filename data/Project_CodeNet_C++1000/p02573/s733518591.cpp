#include<iostream>
#include <vector>
using namespace std;
const int N = 2e5 + 10;
int ans=0,res=0;
int n , m ;
int vist[N];
bool cycle;
vector<vector<int> > v(N);
void dfs(int n , int p){
    vist[n] = true;
    for(int i = 0; i < v[n].size() ;i++){
        int cur = v[n][i];
        if(!vist[cur])
            {ans++;dfs(cur , n);}
        else if(cur != p)cycle = true;
    }
}
int main(){
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        int x , y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    // finding number of components
    int number_of_component = 0;
	for(int i = 1; i <= n ; i++){
		if(!vist[i]){
		    ans=1;
			dfs(i , -1);
			res=max(res,ans);
			number_of_component++;
		}
	}
	cout<<res<<endl;
    return 0;
}