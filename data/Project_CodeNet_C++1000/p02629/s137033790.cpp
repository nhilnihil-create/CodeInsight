#include <bits/stdc++.h>

using namespace std;

int main()
{
    stack<char> out;
    long long int n;
    cin>>n;
    while(n)
    {
        --n;
        out.push('a'+n%26);
        n/=26;//number of alphabet letters i.e base
    }
    while(!out.empty()){
        cout<<out.top();
        out.pop();
    }
    return 0;
}
