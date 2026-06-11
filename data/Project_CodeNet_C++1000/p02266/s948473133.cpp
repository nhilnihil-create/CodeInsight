#include<iostream>
using namespace std;

int main()
{
	int point[20000], width = 0, top = 0
		, volume[10000] = { }, count = 0, sum = 0
		, tmp = 0, height = 0, volumer[10000], rcount = 0;
	char c;
	for (int i = 0; cin >> c; i++)
	{
		width++;
		switch (c)
		{
		case '_':
			point[i] = 0;
			break;
		case '/':
			point[i] = 1;
			height++;
			break;
		case '\\':
			point[i] = -1;
			height--;
			break;
		}
		if (height > 0)
		{
		    top = i;
		    height = 0;
		}
	}
	height = 0;
	for (int i = 0; i <= top; i++)
	{
	    switch(point[i])
	    {
        case 0:
            tmp += height * 2;
            break;
        case 1:
            if (height > 1)
            {
                tmp += height * 2 - 1;
                height--;
            }
            else if (height == 1)
            {
                height = 0;
                tmp++;
                volume[count] = tmp / 2;
                count++;
                tmp = 0;
            }
            break;
        case -1:
            tmp += height * 2 + 1;
            height++;
            break;
	    }
	}
	height = tmp = 0;
	for (int i = width - 1; i >= top; i--)
	{
		switch (point[i])
		{
		case 0:
			tmp += height * 2;
			break;
		case 1:
			tmp += height * 2 + 1;
			height++;
			break;
		case -1:
			if (height > 1)
			{
				tmp += height * 2 - 1;
				height--;
			}
			else if (height == 1)
			{
				height = 0;
				tmp++;
				volumer[rcount] = tmp / 2;
				rcount++;
				tmp = 0;
			}
			break;
		}
	}

	for (int i = 0; i < count; i++)
		sum += volume[i];
	for (int i = 0; i < rcount; i++)
	    sum += volumer[i];
	cout << sum << endl;
	cout << count + rcount;
	for (int i = 0; i < count; i++)
		cout << " " << volume[i];
	for (int i = rcount - 1; i >= 0; i--)
	    cout << " " << volumer[i];
	cout << endl;

	return 0;
}
