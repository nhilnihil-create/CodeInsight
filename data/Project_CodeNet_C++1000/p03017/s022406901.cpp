#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<string>
#include<bitset>
#include <sstream>
#include<queue>
#include<set>
#include<iomanip>
#define rep(i,n) for(ll i=0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<double,double>P;

int main()
{
    int n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    string s;
    cin>>s;
    a--,b--,c--,d--;
    bool aflag=true;
    bool bflag=true;
    bool take=true;
    int apos=a;
    int bpos=b;
    while(bflag)
    {
        if(bpos==d)break;
        
        if(bpos==n-1)bflag=false;

        if(s[bpos+1]!='#')
        {
            bpos+=1;
        }
        else if(s[bpos+2]!='#')
        {
            bpos+=2;
        }
        else
        {
            bflag=false;
            break;
        }

    }
    while(aflag)
    {
        if(apos==c)break;

        if(apos==n-1)aflag=false;

        if(s[apos+1]!='#')
        {
            apos+=1;
        }
        else if(s[apos+2]!='#')
        {
            apos+=2;
        }
        else
        {
            aflag=false;
            break;
        }

    }
    int count=0;
    if(c>d)
    {
        for(int i=b-1;i<=d+1;i++)
            {
                if(s[i]=='.')
                {
                    count++;
                }
                else
                {
                    count=0;
                }
                if(count==3)break;
                
            }
        if(count<3)take=false;

    }
            
    

    
    if(aflag && bflag && take)
    {
        
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }

    
}