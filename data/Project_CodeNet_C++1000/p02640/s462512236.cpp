#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

#define rapid_io() ios::sync_with_stdio(false);cin.tie(0);
#define endl '\n'
#define pb push_back
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()

int main()
{
    rapid_io();
    int x,y;
    cin>>x>>y;
    int n1=0,ans=0;
    if(y/2==x && y%2==0)
        cout<<"Yes"<<endl;
    else if(y/4==x && y%4==0)
        cout<<"Yes"<<endl;
    else{
    for(int i=1;i<=x;i++)
    {
        n1=i*2;

        int ck=y-n1;
        if(ck>=4 && ((ck%4)==0 && (ck/4==x-i)))
        {
            ans=1;
            break;
        }

    }
    if(ans)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    }


    return 0;
}


