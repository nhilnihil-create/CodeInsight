#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
 
using namespace std;
 
#define PB push_back
#define MP make_pairA
#define REP(i,n) for(int i=0;i<(n);i++)
int main()
{
    int m,d;
    cin>>m>>d;
    int cnt=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=20;j<=d;j++)
        {
            if(j%10>=2&&i==(j/10)*(j%10))cnt++;
        }
    }
    cout<<cnt<<endl;
}
