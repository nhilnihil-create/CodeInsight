#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<math.h>
using namespace std;
int main()
{
long long n;
cin >> n;
string s;
while(n--)
{
s+=('a'+(n+25/26)%26);
n=n/26;
}
reverse(s.begin(),s.end());
cout<<s;
return 0;
}
    