#include <bits/stdc++.h>
#define SIZE 10
#define PI 3.141592653589793

using namespace std;
typedef long long ll;


int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	int i,j;
	int start;
	int end;
	bool flag=true;
	string S;
	string S1="";
	string S2="";

	cin >> S;

	N=S.size();
	
	S1=S.substr(0,N/2);
	S2=S.substr((N+3)/2-1,N-1);

	for(i=0;i<N/2;i++)
		if(S[i]!=S[N-1-i]) flag=false;

	if(flag && N==3){
		cout << "Yes" << endl;
		return 0;
	}

	N=S1.size();

	for(i=0;i<N/2;i++)
		if(S1[i]!=S1[N-1-i]) flag=false;

	for(i=0;i<N/2;i++)
		if(S2[i]!=S2[N-1-i]) flag=false;

	if(flag)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}

