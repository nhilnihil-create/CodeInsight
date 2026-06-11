#include<bits/stdc++.h>
using namespace std;
int n,k,c; 
string s;
void solve(){
	cin>>n>>k>>c>>s;
	s = '#' + s;
	vector<int> earliest(k+1,0),latest(k+1,0);
	int i=1,j=1;
	while(i<s.length()&&j<=k){
		if(s[i]=='o'){
			earliest[j++] = i;
			i+=c+1;
		}else{
			i++;
		}
	}
	i=s.length()-1,j=k;
	while(i>0&&j>=1){
		if(s[i]=='o'){
			latest[j--] = i;
			i-=c+1;
		}else{
			i--;
		}
	}
	for(i=1;i<k+1;i++)if(earliest[i]==latest[i])cout<<earliest[i]<<"\n";
}

int main()
{
  solve();
  return 0;
}