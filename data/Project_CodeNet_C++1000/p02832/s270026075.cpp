#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <climits>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

#define INF INT_MAX/3
#define REP(i,n) for(int i=0;i<n;i++)

int main(){
	
	int N;
	vector<int> arr;
	cin>>N;
	arr.resize(N);

	REP(i,N)cin>>arr[i];

	int index = 1;	
	int ans = 0;
	REP(i,N){
	
		if(arr[i] == index){
			index++;
		}
		else{
			ans++;
		}
	}

	if(ans == N){
		cout<<-1<<endl;
	}
	else{
		cout<<ans<<endl;
	}
	return 0;

}

