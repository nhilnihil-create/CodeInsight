#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <cstring>
#include <sstream>
#include <stdlib.h>

using namespace std;

int main (void)
{
	for (int u = 0; u < 5; u++)
	{
		int co = 0;
		int a = 0;
		cin >> a;
		if (a == 0)
		{
			break;
		}

		int o = 0;
		o = 1000 - a;
        for (int i = 0; i < 100; i++)
        {
	        if (o == 0)
	        {
		        break;
	        }
	        if (o >= 500)
		    {
			    co++;
			    o -= 500;
		    }
		    else if (o >= 100)
		    {
			    co++;
			    o -= 100;
		    }
		    else if (o >= 50)
		    {
			    co++;
			    o -= 50;
		    }
		    else if (o >= 10)
		    {
			    co++;
			    o -= 10;
		    }
		    else if (o >= 5)
		    {
			    co++;
			    o -= 5;
		    }
		    else if (o >= 1)
		    {
			    co++;
			    o -= 1;
		    }
        }
		cout << co << endl;
	}
}

