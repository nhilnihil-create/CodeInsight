#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<map>
#include<list>
#include<cctype>
#include<utility>
#include<algorithm>
#include<cctype>
using namespace std;

int main()
{
	int n;
	while(cin >>n && n!=0){
		int sum = 0;
		vector<int>s(n);
		for(int i=0;i<n;i++){
			cin >> s[i];
			sum += s[i];
		}
		double avg = (double)sum/n;
		double a=0;
		for(int i=0;i<n;i++){
			a += (s[i]-avg)*(s[i]-avg);
		}
		a /= n;
		printf("%.7f\n",sqrt(a));
	}

    return 0;
}