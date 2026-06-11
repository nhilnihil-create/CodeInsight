#include<bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

template<class T>bool chmax(T &a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,T b){if(a>b){a=b;return 1;}return 0;}

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};

int main(){
	int n;
	cin>>n;
	vi t(n);
	string s[50];
	for (int i = 0; i < n; i++){
		cin>>s[i]>>t[i];
	}
	string x;
	cin>>x;
	
	int time=0;
	for (int i = 1; i < n; i++){
		if(s[i-1]==x){
			for (int j = i; j < n ; j++){
				time+=t[j];
			}
			break;
		}
	}

	cout<<time<<endl;

	return 0;
}
