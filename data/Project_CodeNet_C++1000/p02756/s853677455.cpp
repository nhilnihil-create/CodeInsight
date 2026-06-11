#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll i, temp,t, n,j, a[200600], ans, k;
bool cond;
list<char>L;
list<char>::iterator it;
string s;
char c;
int main()
{
    //I am Monim, a tiny creature of Allah
    cin >> s;
    temp = s.size();
    for(i=0;i<temp;i++)
    {
        L.push_back(s[i]);
    }
    cin >> n;
    cond = true;
    for(i=0;i<n;i++)
    {
        cin >> j;
        if(j==2)
        {
            cin >> k >> c;
            if(cond)
            {
                if(k==1)
                    L.push_front(c);
                else
                    L.push_back(c);
            }
            else{
                if(k==1)
                    L.push_back(c);
                else
                    L.push_front(c);
            }
        }
        else{
            cond = 1-cond;
        }
    }
    if(!cond)
        reverse(L.begin(), L.end());
    for(it=L.begin();it!=L.end();it++)
            cout << *it;
    return 0;
}
