#include <bits/stdc++.h>
using namespace std;

int print_range_array(deque<pair<int,int>> &r);

int main()
{
	int n;
	cin >> n;

	vector<int> x(n);
	vector<int> l(n);
	for (int i=0;i<n;++i)
	{
		cin >> x.at(i) >> l.at(i);
	}

	deque<pair<int,int>> r;
	for (int i=0;i<n;++i)
	{
		r.push_back(make_pair(x[i]+l[i],x[i]-l[i]));
		//r.at(i).first=x[i]-l[i]+1;
		//r.at(i).second=x[i]+l[i]-1;
	}

	sort(r.begin(),r.end());
	//print_range_array(r);
	//fprintf(stderr,"deque size: %d\n",r.size());

	int count=0;
	int last=-1000000000; 
	for (;;)
	{
		while ((r.size()>0)&&(r.front().second<last))
		{
			r.pop_front();
		}

		if (r.size()<=0)
		{
			break;
		}

		++count;
		pair<int,int> p=r.front();
		r.pop_front();
		last=p.first;

		while ((r.size()>0)&&(r.front().first<last))
		{
			r.pop_front();
		}
	}

	cout << count << endl;

}

int print_range_array(deque<pair<int,int>> &r)
{
	for (int i=0;i<r.size();++i)
	{
		fprintf(stderr,"%d %d\n",r.at(i).first,r.at(i).second);
	}
	return 0;
}

	

