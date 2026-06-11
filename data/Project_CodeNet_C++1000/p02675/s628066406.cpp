#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

typedef long long ll;
const ll mod=1e9+7;
const int N=200000;

void Run()
{
     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
int a[N];
set<int>v;
int main()
{
    Run();
   int n;
   cin>>n;
   n%=10;
   if(n==2||n==5||n==4||n==7||n==9)
    cout<<"hon";
   else if(n==0||n==1||n==6||n==8)
    cout<<"pon";
   else
    cout<<"bon";
}
