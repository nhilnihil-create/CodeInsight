#include <iostream>
#include <vector>
#include <algorithm>
#define vi vector<int>
#define REP(n) for(int i=0;i<n;i++)
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	vi v;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
	sort(v.begin(),v.end());
	REP(v.size()){
		if(i) cout<<" "<<v[i]; 
		else cout<<v[i];
	}
	cout<<endl;

}