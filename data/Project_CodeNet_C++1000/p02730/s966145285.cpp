#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	string S;
	cin >> S;
	int N = S.size();

	string RS = S;
	string S1 = S.substr(0, (N-1)/2);
	string RS1 = S1;
	string S2 = S.substr((N+3)/2 - 1);
	string RS2 = S2;
	
	reverse(RS.begin(), RS.end());
	reverse(RS1.begin(), RS1.end());
	reverse(RS2.begin(), RS2.end());

	if(S == RS && S1 == RS1 && S2 == RS2){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	return 0;

}