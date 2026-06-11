#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <list>
#include <numeric>
#include <map>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
//================================================

int a = 0, b = 0, c, d, n, k=0;
string s, t;


int main()
{
	cin >> n >> k;
  if(k!=1)
	cout << n - k << endl;
  else
    cout<<0<<endl;
	return 0;
}