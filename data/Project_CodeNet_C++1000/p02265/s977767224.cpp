#include<cstdio>
#include<list>
#include<algorithm>
#include<stdlib.h>
using namespace std;

int main()
{
	int key;
	int n;
	char cmd[20];
	list<int> v;
	
	scanf("%d", &n);
	
	for(int i = 0; i<n; i++)
	{
		scanf("%s %d", cmd, &key);
		if(cmd[0]=='i')
		{
			v.push_front(key);
		}
		else if(cmd[0]=='d')
		{
			if(cmd[6]=='F')
			{
				v.pop_front();
			}
			else if(cmd[6]=='L')
			{
				v.pop_back();
			}
			else
			{
				for(list<int>::iterator it = v.begin(); it != v.end(); it++)
				{
					if( *it == key )
					{
						v.erase(it);
						break;
					}
				}
			}
		}	
	}


	
	int i = 0;
	for(list<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		if(i++) printf(" ");
		printf("%d", *it);
	}
	printf("\n");
//	system("pause");
	return 0;
}
