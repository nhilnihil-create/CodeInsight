#include<iostream>
#include<vector>
#define lli long long int
#include<climits>
#include<unordered_map>
#include<algorithm>
#include<bitset>
#include<map>
#define pb push_back
using namespace std;

int main()
{
   
    int n;
    string s1,s2;
    cin>>n>>s1>>s2;
    string a;
    for(int i=0;i<n;i++)
    {
        a.pb(s1[i]);
        a.pb(s2[i]);
    }
    cout<<a<<endl;
    
}

