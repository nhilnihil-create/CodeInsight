#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<algorithm>
#define ll long long
using namespace std;
struct dog {
	string a;
	int b;
};
int main()
{
	//dog shiba; dog pa;
	//cin >> shiba.a >> pa.a;
	//cin >> shiba.b >> pa.b;
	//string key;
	//cin >> key;
	//if (shiba.a == key)shiba.b -= 1;
	//else if (pa.a == key)pa.b -= 1;
	//cout << shiba.b << " " << pa.b;

	//string key;
	//cin >> key;
	//for (int i = 0; i < key.length(); i++)
	//{
	//	cout << "x";
	//}

	int n;
	cin >> n;
	vector<ll>dog;
	for (int i = 0; i < n; i++)
	{
		ll a;
		cin >> a;
		dog.push_back(a);
	}
	sort(dog.begin(), dog.end());
	for (int i = 0; i+1 < n; i++)
	{
			if (dog[i] == dog[i+1])
			{
				cout << "NO";
				exit(0);
			}	 
	}

	cout << "YES";
}

