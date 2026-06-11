#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<map>
#include<array>
#include<cstring>
#include<numeric>
#include<string>
#include<set>
#include<cstdio>
#include<cmath>
#include<unordered_map>
#include<bitset>
typedef long long ll;
typedef long double ld;
using namespace std;

int main()
{
    int n;
    string s;
    cin>>n>>s;
    int sum=0;
    for(int i=0; i<s.size()-2; i++){
        if(s[i]=='A' && s[i+1]=='B' &&s[i+2]=='C')
            sum++;
    }
    cout<<sum<<"\n";
    return 0;
}
