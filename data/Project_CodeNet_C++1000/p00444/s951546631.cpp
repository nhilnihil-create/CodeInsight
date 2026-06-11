#include<iostream>
#include<string>

using namespace std;

int main(){
	/*
	//数あて
	int n;
	cin >> n;
	int p[200][3];

	for(int i=0;i<n;i++)
	{
		cin >> p[i][0] >> p[i][1] >> p[i][2];
	}

	int _p;
	for(int k=0;k<3;k++)
	{
		for(int i=0;i<n;i++)
		{
			_p = p[i][k];
			for(int j=i+1;j<n;j++)
			{
				if(_p == p[j][k])
				{
					p[i][k] = 0;
					p[j][k] = 0;
				}
			}
		}
	}

	for(int i=0;i<n;i++)
	{
		cout << p[i][0] + p[i][1] + p[i][2] << endl;
	}
	*/

	/*
	//得点
	int ai,am,as,ae,bi,bm,bs,be;
	cin >> ai >> am >> as >> ae >> bi >> bm >> bs >> be;
	int answer=ai+am+as+ae;
	if(answer < bi+bm+bs+be)
	{
		answer=bi+bm+bs+be;
	}
	cout << answer << endl;
	*/
	
	//おつり
	int onum;
while(true){
		int N;
		cin >> N;
		if(N == 0) break;
		onum=0;
		int oturi = 1000-N;
		if(oturi >= 500)
		{
			onum++;
			oturi -= 500;
		}
		while(oturi>=100)
		{
			onum++;
			oturi -= 100;
		}
		if(oturi >= 50)
		{
			onum++;
			oturi -= 50;
		}
		while(oturi>=10)
		{
			onum++;
			oturi -= 10;
		}
		if(oturi >= 5)
		{
			onum++;
			oturi -= 5;
		}
		while(oturi>=1)
		{
			onum++;
			oturi -= 1;
		}
		 cout << onum << endl;
	}
   
	
	return 0;
}
