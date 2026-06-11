#include<bits/stdc++.h>

using namespace std;

int main()
{  
    int n;
    cin>>n;
    map<string,int> mp;
    for(int i = 1;i<=n;i++)
    {

        string temp = to_string(i);
        char c1 = temp[0];
        char c2 = temp.back();
        temp.clear();
        temp += c1;
        temp += c2;
        mp[temp]++;
    }

    long long answer = 0;

    for(pair<string,int> p:mp)
    {

        string s = p.first;
        if(s[0] == s[1])
        {
            int x = p.second;
            answer += (x * x);
        }
        else
        {
            int x = p.second;
            swap(s[0],s[1]);
            int y = mp[s];
            answer += (x*y);
        }
        
    }

    cout<<answer;
    return 0;
}