#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <string>
#include <stack>
#include <stdlib.h>
#include <sstream>
using namespace std;
string a;
int A, b, c, d;
stack<int> s;
int main()
{
	while(cin >> a)
	{
		if(a=="+")
		{
			b=s.top();
			s.pop();
			c=s.top();
			s.pop();
			s.push(c+b);
		}
		else if(a=="-")
		{
			b=s.top();
			s.pop();
			c=s.top();
			s.pop();
			s.push(c-b);
		}
		else if(a=="*")
		{
			b=s.top();
			s.pop();
			c=s.top();
			s.pop();
			s.push(c*b);
		}
		else
		{
			stringstream ss;
		    ss << a;
		    ss >> A;
		    ss.clear();
    		ss.str("");
    		s.push(A);
		}
	}
	cout << s.top() << endl;
	return 0;
}