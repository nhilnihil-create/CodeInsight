#include<bits/stdc++.h>
using namespace std;

#define ll long long int

static const auto _____ = []() {
    // fast IO code : this I understand
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(0);
    return 0;
}();

int main(){
	int n;
	cin>>n;
	int a[n][2];
	int cnt = 0;
	int flag = 0;
	for(int i=0;i<n;i++){
		cin>>a[i][0]>>a[i][1];
		if(a[i][0]==a[i][1] ){
			cnt++;
			if(cnt == 3)
				flag = 1;
		}
		else 
			cnt = 0;
	}
	if(flag)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0;
}
