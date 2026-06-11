using namespace std;
#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define INFINITE 1e9 + 5
#define MOD 1000000007
#define MAXN 100001 
#define pll pair<ll,ll>
#define pii pair<int,int>
#define debugArray(arr) cout << #arr<<" : "<<endl;for(int i : arr){cout << i <<", ";} cout <<endl;
#define debugVariable(x) cout <<#x<<"="<<x<<"\n";
#define check(x) cout<<"CHECK="<<#x<<"\n";
int X[4]={1,0,-1,0};
int Y[4]={0,1,0,-1};
int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);
    cout.tie(0);
    int test;
    test=1;
    while(test--)
    {
        int num;
        cin>>num;
        if(num%1000!=0)
        {
            int x=num/1000;
            x=1000*x+1000;
            cout<<x-num;
        }   
        else
        {
            cout<<0;
        }
        
    }
}