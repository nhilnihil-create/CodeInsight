#include<iostream>
#include<vector>
//#include<stdio.h>
//#define FOR(i,k,n) for((i)=(k);(i)<(n);(i)++)
#define REP(i,n) for (int i=0;i<(n);i++)
#define pb push_back
//#define all(a) (a).begin(),(a).end()
using namespace std;

int main(){
	int n,q,s,temp,i,j;
	int count=0;
	vector<int> S;
	cin>>n;
	REP(i,n){
		cin>>s;
		//S.push_back(s);
		S.pb(s);
	}
	
	//sort(S.begin(),S.end());
	//sort(all(S));

	//REP(i,n){
		//FOR(j,i+1,n){
			//if(S[i]==S[j])S[i]=-1;
			//else if(S[i]<S[j])break;
		//}
	//}

	cin>>q;
	REP(i,q){
		cin>>temp;
		REP(j,n){
			if(temp==S[j]){
				count++;
				break;}
		}
	}
	cout<<count<<endl;
	return 0;
}