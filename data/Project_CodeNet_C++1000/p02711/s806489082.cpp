#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

string long_division(string number, LL divisor)
{
    string ret = "";
    LL temp = 0;
    queue<LL>q;

    for(int i=0; i<number.size(); i++)
    {
        temp = (temp * 10) + (number[i] - '0');
        q.emplace(temp/divisor);
        temp %= divisor;
    }

    if(q.empty()) return "0";

    while(q.front()==0) q.pop();
    while(!q.empty())
    {
        ret += q.front() + '0';
        q.pop();
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    /*for(int i=0; i<=9; i++) cout<<"value["<<i<<"] = "<<i<<";\n";
    for(int i=10; i<=32; i++) cout<<"value["<<i<<"] = '"<<(char)(i+55)<<"';\n";*/

    //int t; cin>>t; while(t--) {
        int n;
        cin>>n;
        while(n)
        {
            if(n%10==7)
            {
                cout<<"Yes\n";
                return 0;
            }

            n /= 10;
        }

        cout<<"No\n";
    //}

    return 0;
}