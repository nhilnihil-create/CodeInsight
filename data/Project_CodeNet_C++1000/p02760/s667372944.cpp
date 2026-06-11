#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	int i, j, a[3][3];
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			cin >> a[i][j];
		}
	}
	int n;
	cin >> n;
	map<int, int> b;
	for(i=0; i<n; i++){
		int x;
		cin >> x;
		b[x]++;
	}
	bool flag = false;
	int count_row = 0, count_dia = 0, count_col = 0;
	for(i=0; i<3; i++){
		count_row = 0;
		for(j=0; j<3; j++){
			if(i==j && b[a[i][j]]) count_dia++;
			if(b[a[i][j]]){
				count_row++;
				//b[a[i][j]]--;
			}
		}
		//cout << count_row << " " << count_dia << endl;
		if(count_row==3){
			flag = true;
			break;
		}
	}
	if(flag || count_dia==3){
		cout << "Yes\n";
		return 0;
	}
	else{
		for(j=0; j<3; j++){
			count_col = 0;
			for(i=0; i<3; i++){
				if(b[a[i][j]]) count_col++;
			}
			if(count_col==3){
				flag = true;
				break;
			}
		}
		if(flag) cout << "Yes\n";
		else if(b[a[0][2]] && b[a[1][1]] && b[a[2][0]]) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}
