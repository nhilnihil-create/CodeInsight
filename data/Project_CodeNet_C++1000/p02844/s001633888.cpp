#include <iostream>
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++) //n回繰り返すときだけ使う普通はforで楽しないのがいいかな

using namespace std;
typedef long long int ll;
int main()
{        
    int n;
    string s;
    cin >>n >>s;
    int ans=0;

    for(char i='0';i <= '9';i++)
    {
        for(char k='0';k<='9';k++)
        {
            for(char j='0';j<='9';j++)
            {
                queue<char> q;
                q.push(i);
                q.push(j);
                q.push(k);

                for(int l=0;l<s.size();l++)
                {
                    if(q.front()==s[l])
                    {
                        q.pop();
                    }

                    if(q.size()==0)
                    {
                        ans++;
                        break;
                    }
                }
            }
        }
        
    }
     cout << ans << endl;



}
