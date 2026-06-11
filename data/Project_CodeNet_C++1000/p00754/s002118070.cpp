#include<stdio.h>
#include<string.h>
#include<stack>
int main()
{
	char*p,s[128],*q;
	while(q=fgets(s,128,stdin),*s-'.')
	{
		std::stack<int>c;
		for(p=s;*p;++p)
		{
			if(strchr("[(",*p))c.push(*p);
			if(strchr("])",*p))if(c.empty()||c.top()!=*p-(*p-')'?2:1))q=0;
			else c.pop();
		}
		if(!c.empty())q=0;
		puts(q?"yes":"no");
	}
	return 0;
}