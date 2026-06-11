#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  	int b,p=1000;
  	cin >> b;
  	while(b>p)
      p+=1000;
  	cout << p-b;
    return 0;
}