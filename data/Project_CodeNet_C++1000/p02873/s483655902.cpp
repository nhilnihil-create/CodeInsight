#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long inf=1000000007;

int main(){
	string s;
	cin>>s;
	vector<int> left((int)s.size()+1,0);
	vector<int> right=left;
	int cnt=0;

	for(int i=0;i<(int)s.size();i++){
		if(s.at(i)=='<'){
			cnt++;
		}
		else{
			cnt=0;
		}

		left.at(i+1)=cnt;
	}

	cnt=0;

	for(int i=(int)s.size()-1;i>=0;i--){
		if(s.at(i)=='>'){
			cnt++;
		}else{
			cnt=0;
		}

		right.at(i)=cnt;
	}

	long long ans=0;

	for(int i=0;i<(int)s.size()+1;i++){
		ans+=max(left.at(i),right.at(i));
	}

	cout<<ans<<endl;

	return 0;
}
