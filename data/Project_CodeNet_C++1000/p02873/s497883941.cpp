#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    string str;
    cin>>str;
    ll res = 0, prev = -1, cnt;
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == '<')
        {
            cnt = 0;
            while(str[i] == '<')
            {
                cnt++;
                i++;
            }
            prev = cnt;
            res += (((cnt*(cnt+1)))/2);
            i--;
        }
        else if(str[i] == '>')
        {
            cnt = 0;
            while(str[i] == '>')
            {
                i++;
                cnt++;
            }
            if(prev == -1)res += (((cnt*(cnt+1)))/2);
            else if(prev > cnt)
            {
                cnt--;
                res += (((cnt*(cnt+1)))/2);
            }
            else
            {
                res -= prev;
                res += (((cnt*(cnt+1)))/2);
            }
            i--;
        }
    }
    cout<<res<<endl;
}
