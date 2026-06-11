#include<iostream>
#include<cstdio>

using namespace std;

#define REP(i,n) for(int i = 0;i < n ; i++)
	
int people[100];


bool judge(int n,int a)
{
	REP(i,n)
	{
		if(people[i] != 0 && i != a)return false;
	}
	
	return true;
}



int main()
{
	int n,p;
	
	while(cin >> n >> p,n)
	{
		int flag = false;
		REP(i,100)people[i] = 0;
		for(int i = 0;!flag;i++)
		{
			//cout << p << endl;
			if(p == 0)
			{
				p = people[ i % n ];
				people[i % n] = 0;
			}
			else
			{
				people[i % n]++;
				p--;
				if(p == 0)
				{

					if(judge(n,i%n))
					{
						flag = true;
						cout << i%n << endl;
					}
				}
			}
		}
		
	}
	
	return 0;
}
							