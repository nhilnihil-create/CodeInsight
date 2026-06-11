#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef pair<int, int>P;
typedef tuple<int,int,int,int>T;
#define PI 3.14159265359
#define MOD 1000000007
const int MAX =510000;

int main(){
  	int N,M;
  	cin >>N>>M;
  	vector<vector<int>>A(M+1);//ちょうどi日で終わる仕事の報酬のリスト
  	
  	rep(i,N){
    	int a,b;
    	cin >>a>>b;
      	if(a<=M){A[a].push_back(b);}
    }
  	priority_queue<int>X;//報酬の大きい順に取り出したい
  	int score=0;
	for(int i=1;i<=M;i++){
		for(int j=0;j<A[i].size();j++){
        	X.push(A[i][j]);
        }
      	if(!X.empty()){score+=X.top();X.pop();}
    }
  	cout<<score<<endl;
}