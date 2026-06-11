#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <algorithm>
#include <climits>
#include <set>

#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a,b;
    cin>>a>>b;
    int k=0;
    for(int i=0;i<3;i++)
    {
        if(a[i]==b[i])
            k++;
    }
    cout<<k<<'\n';
}








