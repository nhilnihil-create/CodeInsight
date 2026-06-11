#include <bits/stdc++.h>
using namespace std;

  long long maxAbsValExpr(vector<long long>& x, vector<long long>& y) {
       	long long res=0;
       	long long d[4][x.size()];
        for (int i=0;i<x.size();i++){
            d[0][i]=x[i]+y[i];
            d[1][i]=-x[i]-y[i];
            d[2][i]=x[i]-y[i];
            d[3][i]=-x[i]+y[i];
        }
        for (int i=0;i<4;i++)
        {
        	sort(d[i],d[i]+x.size());
        }

        for (int i=0;i<4;i++)
        {
        	res=max(res,d[i][x.size()-1]-d[i][0]);
        }
        return res;
    }
int main()
{
	int n;
	cin >> n;
	
		vector <long long> x(n);
		vector <long long> y(n);

	for(int i=0;i<n;i++) cin >> x[i] >> y[i];

	cout << maxAbsValExpr(x,y);
	return 0;
}