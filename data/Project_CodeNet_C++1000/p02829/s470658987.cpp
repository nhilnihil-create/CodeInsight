
#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(inti=a;i<=b;i++)

typedef long long int ll;
typedef vector<int>vi;
typedef pair<int,int>pi;



int main()
{

vector<int> s(3);
int a,b;
cin>>a>>b;

s[a-1]++;
s[b-1]++;

for(int index = 0;index < 3 ;index++)
{
    if(!s[index])
    {
        cout<<index+1<<endl;
        break;
    }
}

 return 0;
}
