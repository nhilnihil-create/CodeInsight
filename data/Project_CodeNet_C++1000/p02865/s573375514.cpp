#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#define MOD 1000000007
#define INT long long int
#define REP(i,n) for(int(i)=0;(i)<(n);(i)++) 
using namespace std;
const long long INF = numeric_limits<long long>::max();


int main()
{
    int N;
    cin>>N;
    int ans;
    ans = N/2 - 1 * (N%2==0);
    cout<<ans<<endl;
    return 0;
}