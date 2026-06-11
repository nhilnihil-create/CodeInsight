 #include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>

using namespace std;
#define long long int
int32_t main()
{
	int i,j,k,l,x,y,z;
	string s;
	int N;
	int S[1<<18];
	cin>>N;
	for(int i=0;i<(1<<N);i++)
		cin>>S[i];
	sort(S,S+(1<<N));
	multiset<int> T;
	for(int i=0;i<(1<<N)-1;i++)
		T.insert(S[i]);

	vector<int> V;
	V.push_back(S[(1<<N)-1]);
	for(int i=0;i<N;i++)
	{
		vector<int> W=V;
		for(int i=0;i<V.size();i++)
		{
			auto it=T.lower_bound(V[i]);
			if(it==T.begin())
			{
				cout<<"No"<<endl;
				return 0;
			}
			it--;

			W.push_back(*it);
			T.erase(it);
		}
		sort(W.begin(),W.end());
		reverse(W.begin(),W.end());
		swap(W,V);
	}
	cout<<"Yes"<<endl;
	return 0;
}