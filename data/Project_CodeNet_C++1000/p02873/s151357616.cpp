#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	int n=(int)s.length()+1;
	vector<int> v(n,0);
	int count = 0;
	for(int i=0;i<n-1; i++){
		if (s[i]=='<'){ 
			count+=1;
			v[i+1] = count;
		}
		else count=0;
	}
	count = 0;
	for(int i=n-2;i>=0; i--){
		if (s[i]=='>'){ 
			count+=1;
			v[i] = max(count,v[i]);
		}
		else count=0;
	}
	long long sum=0;
	for(int x: v) sum+=x;
	cout << sum << endl;
	/*for(int i=0;i<n;i++){
		cout << v[i] << " ";
		if(i!=n-1) cout << s[i] << " ";
	}*/
			
     
}
