#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int INF = 0x3f3f3f3f;

void Bubble(int m[], char str[], int n)
{
	int flag = 1;
    while(flag)
    {
        flag = 0;
        for(int i = n-1; i > 0; i--)
        {
            if(m[i] < m[i-1])
            {
                int temp = m[i];
                m[i] = m[i-1];
                m[i-1] = temp;
                flag = 1;
                char temp1 = str[i];
                str[i] = str[i-1];
                str[i-1] = temp1;
            }
        }
    }
    cout << str[0] << m[0];
    for(int i = 1; i < n; i++)
        cout<<" "<<str[i]<<m[i];
    cout<<endl<<"Stable"<<endl;
}

void Selection(int m[], char str[], int n)
{
	for(int i = 0; i < n; i++)
	{
		int Min = INF, loc = i;
		for(int j = i; j < n; j++)
		{
			if(m[j]<Min)
			{
				Min = m[j];
				loc = j;
			}
		}
		int temp = m[i];
		m[i] = m[loc];
		m[loc] = temp;
        char temp1 = str[i];
        str[i] = str[loc];
        str[loc] = temp1;
	}

	cout << str[0] << m[0];
	for(int i = 1; i < n; i++)
		cout<< " " << str[i] << m[i];
	cout << endl;
}

int main()
{
	int n, m[105], m1[105];
	char str[105], str1[105];
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> str[i] >> m[i];
	for(int i = 0; i < n; i++)
	{
		m1[i] = m[i];
		str1[i] = str[i];
	}
	Bubble(m,str,n);
	Selection(m1, str1, n);
	int flag = 1;
	for(int i = 0; i < n; i ++)
		if(str[i] != str1[i])
			flag = 0;
	if(flag)
		cout << "Stable" << endl;
	else
		cout << "Not stable" << endl;
	return 0;
}