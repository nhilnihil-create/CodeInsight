#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
int main()
{
    string str;
    cin>>str;
    set<char> s;
    for(int i=0;i<4;i++)
        s.insert(str[i]);
    if(s.size() == 2)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
	return 0;
}