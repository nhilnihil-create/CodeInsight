#include <bits/stdc++.h>

using namespace std;

int main(){
	string s; cin >> s;
	vector<bool> seq;
	vector<int> R;
	vector<int> L;
	for(int i = 0; i < s.length(); i++){
		seq.push_back(s[i] == 'R');
		if(s[i] == 'R')
			R.push_back(i);
		else
			L.push_back(i);
	}
	
	int nextDiff = s.length() - 1;
	vector<int> result(s.length(), 0);

	for(int i = R.size() - 1; i >= 0; i--){
		if(seq[R[i]+1]){ // the right is R
			int d = nextDiff - R[i];
			if(d & 1){
				result[nextDiff-1]++;
			} else {
				result[nextDiff]++;
			}
		}
		else{ //the right is L
			nextDiff = R[i] + 1;
			result[nextDiff-1]++;
		}
	}

	for(int i = 0; i < L.size(); i++){
		if(seq[L[i]-1]){ // the left is R
			nextDiff = L[i] - 1;
			result[nextDiff+1]++;
		} else { //the left is L
			int d = L[i] - nextDiff;
			if(d & 1){
				result[nextDiff+1]++;
			} else {
				result[nextDiff]++;
			}
		}
	}

	for(auto x : result){
		printf("%d ", x);
	}
	printf("\n");

	return 0;
}

