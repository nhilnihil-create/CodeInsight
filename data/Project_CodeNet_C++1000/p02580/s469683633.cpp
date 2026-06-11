#include<bits/stdc++.h>

using namespace std;

int main(){
	int h, w, m;
	cin>>h>>w>>m;
	vector<int> col(w + 1, 0);
	vector<int> row(h + 1, 0);
	int A[m];
	int B[m];
	map<pair<int,int>, int> store_AB; 
	for (int i=0; i<m; i++){
		cin>>A[i]>>B[i];
		store_AB[ pair<int,int>(A[i], B[i])] ++;
		row[A[i]]++;
		col[B[i]]++;
	}
	int ans_1 = 0;
	int k = 0;
	int check = 0;
	for (int i=1; i<row.size(); i++){
		if(row[i] > ans_1){
			ans_1 = row[i];
		}
	}
	vector<int> store_1;
	for (int i=1; i<row.size(); i++){
		if(row[i] == ans_1){
			store_1.push_back(i);
		}
	}
	int ans_2 = 0;
	int l = 0;
	for (int i=1; i<col.size(); i++){
		if(col[i] > ans_2){
			ans_2 = col[i];
		}
	}
	vector<int> store_2;
	for (int i=1; i<col.size(); i++){
		if(col[i] == ans_2){
			store_2.push_back(i);
		}
	}
	for (int i=0; i<store_1.size(); i++){
		for (int j=0; j<store_2.size(); j++){
			if(store_AB[pair<int,int>(store_1[i], store_2[j])] == 0){
				check = 1;
				break;
			}
		}
		if(check == 1)	break;
	}
	if(check == 1) cout<<ans_1 + ans_2;
	else cout<<ans_1 + ans_2 - 1;
}