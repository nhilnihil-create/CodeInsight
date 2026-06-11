#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<string>

#define rep(i,p) for(long long int i=0;i<p;i++)
#define reep(i,p) for(long long int i=1;i<=p;i++)
#define ll long long

using namespace std;

int main(){

string S;
cin >> S;


ll int N;
N = S.size();
rep(i,N){
	if(i%2 == 0){
		if(S[i] == 'L'){
			cout << "No";
			return 0;
		}
		else{}
	}
	else{
		if(S[i] == 'R'){
			cout << "No";
			return 0;
		}
		else{}
	}
}
cout << "Yes";












	return 0;

}

