#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
string s;
map<int,int>mm;
int main()
{
    mm[0]=1;
	int inv = 1 ;
    cin >> s;
    int num = 0 ;
    long long ans = 0 ;
    for(int i=s.size()-1;i>=0;i--){
        num = (num+(s[i]-'0')*inv)%2019;
        ans+=mm[num];
        mm[num]++;
		inv = inv*10%2019;
    }
    cout << ans <<endl;
    return 0;
}
