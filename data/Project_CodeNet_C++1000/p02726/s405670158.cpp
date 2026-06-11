#include <bits/stdc++.h>
 
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define vll vector<ll>
#define vii vector<ii>
#define debug cout << "Ok" << endl;

using namespace std;

int resp[2050],n,x,y;
bitset<2050>verified;
queue<pair<int,int>>q;

void bfs(){
	while(q.empty()==false){
	
	int i = q.front().first;
	int val = q.front().second;
	q.pop();

		if(verified[i]==false){
			verified[i]=true;

			resp[val]++;

			if(i!=1) q.push(make_pair(i-1,val+1));
			if(i!=n) q.push(make_pair(i+1, val+1));
			if(i==x) q.push(make_pair(y,val+1));
			if(i==y) q.push(make_pair(x,val+1));

		}
	}
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	
	for(int i=0;i<2019;i++){
		resp[i]=0;
	}

	cin >> n >> x >> y;

	for(int i=1;i<=n;i++){

		for(int j= 0;j<n+2;j++){
			verified[j] = false;
		}

		q.push(make_pair(i,0));
		bfs();

	}

	for(int k=1;k<n;k++){
			cout << resp[k]/2 << endl;
	}

	return 0;
}