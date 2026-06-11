#include<iostream>
using namespace std;

int len(char s[]){
	int l = 0;
	for(;'a'<=s[l]&&s[l]<='z';l++);
	for(;'A'<=s[l]&&s[l]<='Z';l++);
	return l;
}

int min(int a, int b, int c){
	if(a<=b&&a<=c) return a;
	if(b<=a&&b<=c) return b;
	return c;
}

int levenshtein(char s1[], char s2[]){
	int n = len(s1);
	int m = len(s2);
	int dp[n+1][m+1]={};

	for(int i=0; i<n+1; i++){
		dp[i][0] = i;
	}

	for(int j=0; j<m+1; j++){
		dp[0][j] = j;
	}

	for(int i=1; i<n+1; i++){
		for(int j=1; j<m+1; j++){
			if(s1[i-1] == s2[j-1]){
				dp[i][j] = min(dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]);
			}else{
				dp[i][j] = min(dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+1);
			}
		}
	}

	return dp[n][m];
}

int main(){
	char s1[1000], s2[1000];

	cin >> s1 >> s2;
	cout << levenshtein(s1, s2) << endl;

	return 0;
}
