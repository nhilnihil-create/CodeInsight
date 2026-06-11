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
   
    int a,b;
    cin>>a>>b;
    vector<bool>arr(4);
    arr[a] = true;
    arr[b] = true;
    for(int i=1;i<4;i++)
        if(!arr[i])  cout<<i<<endl;
    
}

