#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define what_is(x) cerr << #x << " is " << x << endl;
#define MT make_tuple
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define REP(i,a,b) for (int i = a; i <= b; i++)
#define FOR(i,n) for (int i=0;i < n ; i++)
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
clock_t startTime;
long double getTime(){
	return (long double)(clock()-startTime)/CLOCKS_PER_SEC;
}

int main(){
	startTime=clock();
	int h,w;
	cin >> h >> w;
	string s[h];
	FOR(i,h){
		cin >> s[i];
	}

	int hor[h][w];
	FOR(i,h) FOR(j,w) hor[i][j]=0;

	FOR(i,h){
		int j=0;
		while(j < w){

			while(j< w && s[i][j]=='#') j++;
			int k=j,count=0;
			while(k < w && s[i][k]=='.') {
				k++;
				count++;
			}
			for(int l=j;l<min(k,w);l++){
			 	hor[i][l]=count;
			 	
			}
			
			j=k;
			
		}
		
	}
	
	int ver[h][w];
	FOR(i,h) FOR(j,w) ver[i][j]=0;

	FOR(i,w){
		int j=0;
		while(j < h){
			while(j < h && s[j][i]=='#') j++;
			int k=j,count=0;
			while(k < h && s[k][i]=='.') {
				k++;
				count++;
			}
			for(int l=j;l < min(k,h);l++){
			 	ver[l][i]=count;
				
			}
			j=k;
		}
	}
	int maxAns=-1;
	FOR(i,h)
		FOR(j,w)
			maxAns=max(hor[i][j]+ver[i][j]-1,maxAns);
	cout << maxAns;

	return 0;
}