#include <iostream>
#include<bits/stdc++.h>
#define input ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define ii pair<int,int>
#define dl endl
#define ft first
#define sc second
using namespace std;
string a, b;
int cnt = 0;
int main()
{
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	input;
	cin >> a >> b;
	for (int i = 0; i < a.length(); ++i) if (a[i] != b[i]) cnt++;
	cout << cnt;
}