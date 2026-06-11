
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <map>
#define pb push_back
#define ll long long
#define pii pair<int,int>
#define pll pair<long,long>
using namespace std;
ifstream fin("f.in");
ofstream fout("f.out");
multiset<int,greater<int> > s,ans;
vector<int> v;
int n,nr,i,j;
int main()
{
	cin>>n;
	for(i=0;i<(1<<n);i++)
	{
		cin>>nr;
		s.insert(nr);
	}
	ans.insert(*s.begin());
	s.erase(s.begin());
	bool ok=true;
	for(i=0;i<n;i++)
	{
	    if(ok==true)
        {
            for(int x:ans)
            {
                auto it=s.upper_bound(x);
                if(it==s.end() && ok==true)
                {
                    cout<<"No";
                    ok=false;
                    break;
                }
                v.push_back(*it);
                s.erase(it);
            }
            int siz=v.size();
            for(j=0;j<siz;j++)
            {
                ans.insert(v[j]);
            }
        }
        v.clear();
	}
	if(ok==true)
        cout<<"Yes";
	return 0;
}
