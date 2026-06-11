#include <bits/stdc++.h>
#define rep(i,s,n) for(int i=s;i<n;i++)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
using P=pair<int,int>;
using G=vector<vector<int>>;
using ll=long long;
ll N;

const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
int n,m;
int ans=0;

vector<vector<int>> grid;
vector<ll> H, S;
vector<bool> seen;
vector<ll>sum;
vector<int> pl;

int main(int argc, char **argv){
	int n,d; cin>>n>>d;
	int cnt=1;
	int sum=0;

	sum=2*d+1;
	while(sum<n){
		sum+=2*d+1;
		cnt++;
	}

	cout<<cnt<<endl;
}
