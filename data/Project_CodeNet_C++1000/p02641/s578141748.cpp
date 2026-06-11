#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
int main()
{
    IOS;
    //freopen("inputfile.txt","r",stdin);
    int num,n;cin>>num>>n;
    set <int> s;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        s.insert(x);
    }
    if(s.find(num)==s.end())
    {
        cout<<num<<endl;
        return 0;
    }
    int left = num-1;
    int right = num+1;
    while(1)
    {
        if(s.find(left)==s.end() && s.find(right)==s.end())
        {
            if(abs(num-left)==abs(num-right))
            {
                cout<<min(left,right);
            }
            else (abs(num-left)<abs(num-right))? cout<<left : cout<<right;
                cout<<endl;
            return 0;
        }
        else if(s.find(left)==s.end())right++;
        else if(s.find(right)==s.end())left--;
        else
        {
            left--;
            right++;
        }
    }
}
